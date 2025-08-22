#include <SquidCore.hpp>
#include <SquidPlatform.hpp>
#include <SquidEntryPoint.hpp>

void SquidSetupApplication(Squid::Application& app)
{
	app.LoadEngineModule<Squid::PlatformModule>();
	Squid::WindowComponent& c = app.AddComponent<Squid::WindowComponent>(1250, 780, "My Window", Squid::WindowClosable | Squid::WindowResizable);
}
