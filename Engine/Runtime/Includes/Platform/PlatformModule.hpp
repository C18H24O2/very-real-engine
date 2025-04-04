#ifndef SQUID_PLATFORM_MODULE_HPP__
#define SQUID_PLATFORM_MODULE_HPP__

#include <Platform/PreCompiled.hpp>
#include <Core/Module.hpp>
#include <Utils/TypeList.hpp>

namespace Squid
{
	class SQUID_PLATFORM_API PlatformModule : public Module
	{
		public:
			using Dependencies = TypeList<class CoreModule>;

			PlatformModule();

			static inline bool IsInit() noexcept { return s_instance != nullptr; }
			static PlatformModule& Get();

			void Update() override;

			~PlatformModule() override;

		private:
			static PlatformModule* s_instance;
	};
}

#endif
