#include <Core/CoreModule.hpp>
#include <Core/Logs.hpp>

namespace Mlk
{
	namespace Memory::Internal
	{
		void Init();
		void Shutdown();
	}

	CoreModule* CoreModule::s_instance = nullptr;

	CoreModule::CoreModule() : Module("CoreModule")
	{
		if(s_instance != nullptr)
			FatalError("only one instance of CoreModule can exist at a given time");
		s_instance = this;
		Memory::Internal::Init();
		m_ticks.Init();
	}

	CoreModule& CoreModule::Get()
	{
		Verify(s_instance != nullptr, "CoreModule has not been instanciated");
		return *s_instance;
	}

	CoreModule::~CoreModule()
	{
		Memory::Internal::Shutdown();
		s_instance = nullptr;
	}
}
