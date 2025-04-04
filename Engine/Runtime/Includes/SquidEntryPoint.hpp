#ifndef SQUID_ENTRY_POINT
#define SQUID_ENTRY_POINT

#include <Core/CompilationProfile.hpp>
#include <Core/Application.hpp>
#include <Core/CLI.hpp>
#include <Core/EngineConfig.hpp>
#include <Platform/Unix/UnixInstance.hpp>

// Setup functions defined by the user
extern void SquidSetupApplication(Squid::Application& app);
extern void SquidSetupEngineConfig(Squid::EngineConfig& config);

int main(int ac, char** av)
{
	Squid::CommandLineInterface cli; // Just to initialize it

	Squid::UnixInstance os;
	os.Init(ac, av);

	Squid::EngineConfig config;
	SquidSetupEngineConfig(config);

	Squid::Application app(config);
	SquidSetupApplication(app);

	app.Run();

	app.ShutdownAllEngineModules();

	os.Shutdown();
	return 0;
}

#endif
