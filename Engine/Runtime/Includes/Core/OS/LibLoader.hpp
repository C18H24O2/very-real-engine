#ifndef SQUID_CORE_OS_LIB_LOADER_HPP__
#define SQUID_CORE_OS_LIB_LOADER_HPP__

#include <Core/PreCompiled.hpp>
#include <Utils/NonCopyable.hpp>

namespace Squid
{
	using LibFunc = void (*)(void);
	using LibModule = void*;
	constexpr LibModule NullModule = nullptr;

	class SQUID_CORE_API LibLoader : public NonCopyable
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
