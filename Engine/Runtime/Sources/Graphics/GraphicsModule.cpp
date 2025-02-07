#include <Core/OS/OSInstance.h>
#include <Graphics/Enums.h>
#include <Core/Application.h>
#include <Graphics/GraphicsModule.h>
#include <Core/CLI.h>
#include <Core/Logs.h>
#include <Utils/ConstMap.h>

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
