#include <MlkCore.hpp>
#include <MlkPlatform.hpp>
#include <MlkEntryPoint.hpp>

void MlkSetupEngineConfig(Mlk::EngineConfig& config)
{
}

void MlkSetupApplication(Mlk::Application& app)
{
	app.LoadEngineModule<Mlk::PlatformModule>();
	app.AddComponent<Mlk::WindowComponent>(1250, 780, "My Window", Mlk::WindowClosable | Mlk::WindowResizable);
}
