#include <Graphics/GraphicsModule.hpp>
#include <Core/OS/OSInstance.hpp>
#include <Core/Application.hpp>
#include <Core/Logs.hpp>

namespace Mlk
{
	GraphicsModule* GraphicsModule::s_instance = nullptr;

	GraphicsModule::GraphicsModule() : Module("GraphicsModule")
	{
		if(s_instance != nullptr)
			FatalError("only one instance of GraphicsModule can exist at a given time");
		s_instance = this;
	}

	GraphicsModule& GraphicsModule::Get()
	{
		Verify(s_instance != nullptr, "GraphicsModule has not been instanciated");
		return *s_instance;
	}

	GraphicsModule::~GraphicsModule()
	{
		s_instance = nullptr;
	}
}
