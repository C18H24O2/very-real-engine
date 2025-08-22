set_languages("cxx23")

add_rules("mode.debug", "mode.release", "mode.releasedbg")
set_allowedplats("windows", "mingw", "linux", "macosx", "wasm")
set_allowedmodes("debug", "release", "releasedbg")
set_defaultmode("releasedbg")

set_project("SquidEngine")

if is_mode("debug") then
	add_defines("SQUID_DEBUG")
else
	add_defines("SQUID_RELEASE")
	set_fpmodels("fast")
	add_vectorexts("sse", "sse2", "sse3", "ssse3")
end

add_includedirs("Engine/Runtime/Includes")

set_objectdir("build/Objs/$(os)_$(arch)")
set_targetdir("build/Bin/$(os)_$(arch)")
set_rundir("build/Bin/$(os)_$(arch)")
set_dependir("build/.deps")

set_optimize("fastest")

local renderer_backends = {
	Vulkan = {
		option = "vulkan",
		deps = {"SquidRenderer"},
		packages = {"vulkan-headers"},
		dir = "Renderer/Backends/",
		custom = function()
			add_defines("VK_NO_PROTOTYPES")
			if is_plat("windows", "mingw") then
				add_defines("VK_USE_PLATFORM_WIN32_KHR")
			elseif is_plat("linux") then
				add_defines("VK_USE_PLATFORM_XLIB_KHR")
				add_defines("VK_USE_PLATFORM_WAYLAND_KHR")
				add_packages("libxext", "wayland", { links = {} }) -- we only need X11 headers
			elseif is_plat("macosx") then
				add_defines("VK_USE_PLATFORM_METAL_EXT")
			end
		end
	}
	-- Maybe add more backends
}

local os_interfaces = {
	Unix = {
		dir = "Platform/",
		enabled = is_plat("linux")
	},
	-- TODO : windows, macOS
}

local modules = {
	Core = {
		deps = {},
		custom = function()
			add_headerfiles("Engine/Runtime/Includes/Maths/**.h", "Engine/Runtime/Includes/Maths/**.inl")
		end
	},
	Graphics = {
		option = "graphics",
		deps = {"SquidRenderer"},
		custom = function()
			add_headerfiles("Engine/Runtime/Includes/Maths/**.h", "Engine/Runtime/Includes/Maths/**.inl")
		end
	},
	Renderer = {
		option = "renderer",
		deps = {"SquidCore", "SquidPlatform"},
		public_packages = {"nzsl"},
		custom = function()
			if has_config("embed_rendererbackends", "static") then
				add_defines("SQUID_EMBEDDED_RENDERER_BACKENDS")
				for name, module in table.orderpairs(renderer_backends) do
					if not module.option or has_config(module.option) then
						if module.deps then
							module = table.clone(module, 1) -- swallow clone
							module.deps = table.remove_if(table.clone(module.deps), function(idx, dep) return dep == "SquidRenderer" end)
							if #module.deps == 0 then 
								module.deps = nil 
							end
						end
						ModuleTargetConfig(name, module)
					end
				end
			end
		end
	},
	Platform = {
		option = "platform",
		deps = {"SquidCore"}
	},
}

local sanitizers = {
	asan = "address",
	lsan = "leak",
	tsan = "thread",
}

for opt, policy in table.orderpairs(sanitizers) do
	option(opt, { description = "Enable " .. opt, default = false })

	if has_config(opt) then
		set_policy("build.sanitizer." .. policy, true)
	end
end

if is_plat("wasm") then
	renderer_backends.Vulkan = nil
end

if not has_config("embed_rendererbackends", "static") then
	-- Register renderer backends as separate modules
	for name, module in pairs(renderer_backends) do
		if (modules[name] ~= nil) then
			os.raise("overriding module " .. name)
		end

		modules[name] = module
	end
end

for name, module in table.orderpairs(modules) do
	if module.option then
		option(module.option, { description = "Enables the " .. name .. " module", default = true, category = "Modules" })
	end
end

for name, module in table.orderpairs(system_interfaces) do
	if module.option then
		option(module.option, { description = "Enables the " .. name .. " backend", default = module.default, category = "Modules" })
	end
end

add_rules("build.rendererplugins")

option("static", { description = "Build the engine statically (implies embed_rendererbackends)", default = is_plat("wasm") or false })
option("embed_rendererbackends", { description = "Embed renderer backend code into SquidRenderer instead of loading them dynamically", default = is_plat("wasm") or false })
option("unitybuild", { description = "Build the engine using unity build", default = false })

if has_config("renderer") then
	add_requires("nzsl", { debug = is_mode("debug"), configs = { symbols = not is_mode("release"), shared = not is_plat("wasm", "android") and not has_config("static") } })
end

if is_plat("linux") then
	add_requires("libxext", "wayland", { configs = { asan = false } })
end

if has_config("vulkan") and not is_plat("wasm") then
	add_requires("vulkan-headers")
end

function ModuleTargetConfig(name, module)
	add_defines("SQUID_" .. name:upper() .. "_BUILD")
	if is_mode("debug") then
		add_defines("SQUID_" .. name:upper() .. "_DEBUG")
	end

	if is_plat("wasm") or has_config("static") then
		add_defines("SQUID_".. name:upper() .. "_STATIC", { public = true })
	end

	-- Add header and source files
	for _, ext in ipairs({".h", ".hpp", ".inl"}) do
		if module.dir then
			add_headerfiles("Engine/Runtime/Includes/" .. module.dir .. name .. "/**" .. ext)
			add_headerfiles("Engine/Runtime/Sources/" .. module.dir .. name .. "/**" .. ext, { prefixdir = "private", install = false })
		else
			add_headerfiles("Engine/Runtime/Includes/" .. name .. "/**" .. ext)
			add_headerfiles("Engine/Runtime/Sources/" .. name .. "/**" .. ext, { prefixdir = "private", install = false })
		end
	end

	if module.dir then
		remove_headerfiles("Engine/Runtime/Sources/" .. module.dir .. name .. "/Resources/**.h")
	else
		remove_headerfiles("Engine/Runtime/Sources/" .. name .. "/Resources/**.h")
	end

	-- Add extra files for projects
	for _, ext in ipairs({".nzsl"}) do
		if module.dir then
			add_extrafiles("Engine/Runtime/Includes/" .. module.dir .. name .. "/**" .. ext)
			add_extrafiles("Engine/Runtime/Sources" .. module.dir .. name .. "/**" .. ext)
		else
			add_extrafiles("Engine/Runtime/Includes/" .. name .. "/**" .. ext)
			add_extrafiles("Engine/Runtime/Sources" .. name .. "/**" .. ext)
		end
	end

	if module.dir then
		set_pcxxheader("Engine/Runtime/Includes/" .. module.dir .. name .. "/PreCompiled.hpp")
	else
		set_pcxxheader("Engine/Runtime/Includes/" .. name .. "/PreCompiled.hpp")
	end

	if module.packages then
		add_packages(table.unpack(module.packages))
	end

	if module.public_packages then
		for _, pkg in ipairs(module.public_packages) do
			add_packages(pkg, { public = true })
		end
	end

	if module.deps then
		add_deps(table.unpack(module.deps))
	end

	if module.dir then
		add_files("Engine/Runtime/Sources/" .. module.dir .. name .. "/**.cpp")
	else
		add_files("Engine/Runtime/Sources/" .. name .. "/**.cpp")
	end

	if module.custom then
		module.custom()
	end
end

for name, module in pairs(modules) do
	if module.option and not has_config(module.option) then
		goto continue
	end

	target("Squid" .. name, function()
		set_group("Modules")

		-- handle shared/static kind
		if is_plat("wasm") or has_config("static") then
			set_kind("static")
		else
			set_kind("shared")
		end

		add_includedirs("Engine/Runtime/Sources")
		add_rpathdirs("$ORIGIN")

		if has_config("unitybuild") then
			add_rules("c++.unity_build", { batchsize = 6 })
		end

		on_clean(function(target)
			if target:objectfiles() then
				for _, file in ipairs(target:objectfiles()) do
					if os.exists(file) then
						print("Removing " .. file)
						os.rm(file)
					end
				end
			end
			if target:targetfile() and os.exists(target:targetfile()) then
				print("Removing " .. target:targetfile())
				os.rm(target:targetfile())
			end
		end)

		ModuleTargetConfig(name, module)
	end)

	::continue::
end

rule("build.rendererplugins")
	on_load(function(target)
		if has_config("static") then
			return
		end

		local deps = table.wrap(target:get("deps"))

		if target:kind() == "binary" and table.contains(deps, "SquidRenderer") then
			for name, _ in pairs(renderer_backends) do
				local depName = "Squidel" .. name
				if not table.contains(deps, depName) then -- don't overwrite dependency
					target:add("deps", depName, {inherit = false})
				end
			end
		end
	end)

includes("SandBox/*.lua")
