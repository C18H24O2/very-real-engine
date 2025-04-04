#include <SquidCore.hpp>
#include <SquidPlatform.hpp>
#include <SquidEntryPoint.hpp>

void SquidSetupEngineConfig(Squid::EngineConfig& config)
{
}

void SquidSetupApplication(Squid::Application& app)
{
	app.LoadEngineModule<Squid::PlatformModule>();
	app.AddComponent<Squid::WindowComponent>(1250, 780, "My Window", Squid::WindowClosable | Squid::WindowResizable);
}
