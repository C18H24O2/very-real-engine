#ifndef SQUID_CORE_COREMODULE_HPP__
#define SQUID_CORE_COREMODULE_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/Module.hpp>
#include <Core/Ticks.hpp>
#include <Core/VirtualFileSystem.hpp>
#include <Utils/TypeList.hpp>

namespace Squid
{
	class SQUID_CORE_API CoreModule : public Module
	{
		public:
			using Dependencies = TypeList<>;

			CoreModule();

			static inline bool IsInit() noexcept { return s_instance != nullptr; }
			static CoreModule& Get();

			inline VirtualFileSystem& GetVirtualFileSystem() { return m_filesystem; }
			inline Ticks& GetTicksReference() { return m_ticks; }

			~CoreModule() override;

		private:
			static CoreModule* s_instance;
			Ticks m_ticks;
			VirtualFileSystem m_filesystem;
	};

	SQUID_FORCEINLINE VirtualFileSystem& GetVFS() { Assert(CoreModule::IsInit(), "CoreModule is not init"); return CoreModule::Get().GetVirtualFileSystem(); }
}

#endif
