#include <SquidCore.hpp>
#include <SquidPlatform.hpp>
#include <SquidGraphics.hpp>
#include <SquidEntryPoint.hpp>

void SquidSetupEngineConfig(Squid::EngineConfig& config)
{
	config.preffered_render_api = Squid::RendererDrivers::Vulkan;
}

void SquidSetupApplication(Squid::Application& app)
{
	app.LoadEngineModule<Squid::PlatformModule>();
	app.AddComponent<Squid::WindowComponent>(1250, 780, "My Window", Squid::WindowClosable | Squid::WindowResizable);

	// TODO
}
