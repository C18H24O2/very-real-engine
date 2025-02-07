#ifndef MLK_ENTRY_POINT
#define MLK_ENTRY_POINT

#include <Core/CompilationProfile.hpp>
#include <Core/Application.hpp>
#include <Core/CLI.hpp>
#include <Core/EngineConfig.hpp>
#include <Platform/Unix/UnixInstance.hpp>

// Setup functions defined by the user
extern void MlkSetupApplication(Mlk::Application& app);
extern void MlkSetupEngineConfig(Mlk::EngineConfig& config);

int main(int ac, char** av)
{
	Mlk::CommandLineInterface cli; // Just to initialize it

	Mlk::UnixInstance os;
	os.Init(ac, av);

	Mlk::EngineConfig config;
	MlkSetupEngineConfig(config);

	Mlk::Application app(config);
	MlkSetupApplication(app);

	app.Run();

	app.ShutdownAllEngineModules();

	os.Shutdown();
	return 0;
}

#endif
