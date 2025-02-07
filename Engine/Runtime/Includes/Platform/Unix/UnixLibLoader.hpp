#ifndef MLK_UNIX_LIB_LOADER_HPP__
#define MLK_UNIX_LIB_LOADER_HPP__

#include <Platform/Unix/PreCompiled.hpp>
#include <Core/OS/LibLoader.hpp>

namespace Mlk
{
	class MLK_UNIX_API UnixLibLoader : public LibLoader
	{
		public:
			UnixLibLoader() = default;

			[[nodiscard]]
			LibFunc GetSymbol(LibModule module, const char* symbol) const override;

			[[nodiscard]]
			LibModule Load(const std::filesystem::path& path) override;
			void UnloadLib(LibModule module) override;

			~UnixLibLoader() = default;
	};
}

#endif
