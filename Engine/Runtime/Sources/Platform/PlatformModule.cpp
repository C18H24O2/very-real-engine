#include <Core/Application.hpp>
#include <Platform/PlatformModule.hpp>
#include <Core/Logs.hpp>
#include <Core/Memory/MemoryManager.hpp>

namespace Squid
{
	PlatformModule* PlatformModule::s_instance = nullptr;

	PlatformModule::PlatformModule() : Module("PlatformModule")
	{
		if(s_instance != nullptr)
			FatalError("only one instance of PlatformModule can exist at a given time");
		s_instance = this;
	}

	void PlatformModule::Update()
	{
	}

	PlatformModule& PlatformModule::Get()
	{
		Assert(s_instance != nullptr, "PlatformModule has not been instanciated");
		return *s_instance;
	}

	PlatformModule::~PlatformModule()
	{
		s_instance = nullptr;
	}
}
