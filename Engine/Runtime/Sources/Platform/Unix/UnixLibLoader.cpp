#include <Platform/Unix/UnixLibLoader.hpp>
#include <Core/Logs.hpp>

namespace Squid
{
	[[nodiscard]]
	LibFunc UnixLibLoader::GetSymbol(LibModule module, const char* symbol) const
	{
		void* ptr = dlsym(module, symbol);
		if(ptr == nullptr)
		{
			Error("Unix Library loader : could not load '%' symbol", symbol);
			return nullptr;
		}
		LibFunc func;
		*(void**)(&func) = ptr;
		return func;
	}

	[[nodiscard]]
	LibModule UnixLibLoader::Load(const std::filesystem::path& path)
	{
		LibModule module;
		dlerror(); // clears error flag
		module = dlopen(path.string().data(), RTLD_LAZY | RTLD_GLOBAL);
		if(module == NullModule)
		{
			Error("Unix Library loader : could not load %; %", path, dlerror());
			return NullModule;
		}
		return module;
	}

	void UnixLibLoader::UnloadLib(LibModule module)
	{
		if(module != NullModule)
			dlclose(module);
	}
}
