#ifndef MLK_CORE_OS_LIB_LOADER_HPP__
#define MLK_CORE_OS_LIB_LOADER_HPP__

#include <Core/PreCompiled.hpp>
#include <Utils/NonCopyable.hpp>

namespace Mlk
{
	using LibFunc = void (*)(void);
	using LibModule = void*;
	constexpr LibModule NullModule = nullptr;

	class MLK_CORE_API LibLoader : public NonCopyable
	{
		public:
			LibLoader() = default;

			virtual LibFunc GetSymbol(LibModule module, const char* symbol) const = 0;

			virtual LibModule Load(const std::filesystem::path& path) = 0;
			virtual void UnloadLib(LibModule module) = 0;

			~LibLoader() = default;
	};
}

#endif
