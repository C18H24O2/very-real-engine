target("SimpleWindow")
	add_deps("SquidPlatform")
	if is_plat("linux") then
		set_extension(".x86_64")
	end
	add_files("main.cpp")
	set_targetdir("build/")
