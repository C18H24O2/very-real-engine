#include <Core/OS/OSInstance.hpp>
#include <Renderer/Enums.hpp>
#include <Core/Application.hpp>
#include <Renderer/RendererModule.hpp>
#include <Core/CLI.hpp>
#include <Core/Logs.hpp>
#include <Utils/ConstMap.hpp>

namespace Squid
{
	RendererModule* RendererModule::s_instance = nullptr;

	RendererModule::RendererModule() : Module("RendererModule")
	{
		if(s_instance != nullptr)
			FatalError("only one instance of RendererModule can exist at a given time");
		s_instance = this;
		LoadDriver();
	}

	RendererModule& RendererModule::Get()
	{
		Verify(s_instance != nullptr, "RendererModule has not been instanciated");
		return *s_instance;
	}

	void RendererModule::LoadDriver()
	{
		using DriverLoaderFunctor = RHIRenderer* (*)(void);

		std::multimap<int, RendererDrivers, std::greater<int>> drivers_scores;

		for(std::size_t i = 0; i < RendererDriversCount; i++)
			drivers_scores.insert(std::make_pair(ScoreDriver(static_cast<RendererDrivers>(i)), static_cast<RendererDrivers>(i)));

		if(drivers_scores.upper_bound(0) == drivers_scores.end())
			FatalError("RendererModule : failed to find a suitable render driver");

		#ifndef SQUID_EMBEDDED_RENDERER_BACKENDS
			ConstMap<RendererDrivers, std::filesystem::path> drivers_paths = {
				{ RendererDrivers::Vulkan, SQUID_LIB_PREFIX "SquidelVulkan" SQUID_LIB_EXTENSION },
			};
		#endif

		for(auto& [score, driver] : drivers_scores)
		{
			if(score < 1)
				continue;

			#ifndef SQUID_EMBEDDED_RENDERER_BACKENDS
				LibLoader& loader = OSInstance::GetLibLoader();
				LibModule module = loader.Load(drivers_paths.Find(driver)->second);
				if(module == NullModule)
				{
					Warning("RendererModule : cannot load %, falling back...", drivers_paths.Find(driver)->second);
					continue;
				}

				DriverLoaderFunctor loader_function = reinterpret_cast<DriverLoaderFunctor>(loader.GetSymbol(module, "SquidelLoadRendererDriver"));
				if(!loader_function)
				{
					Warning("RendererModule : cannot load %, no loading symbol found, falling back...", drivers_paths.Find(driver)->second);
					loader.UnloadLib(module);
					continue;
				}

				RHIRenderer* renderer = loader_function();
				if(renderer == nullptr)
				{
					Warning("RendererModule : cannot load %, error while loading the renderer, falling back...", drivers_paths.Find(driver)->second);
						loader.UnloadLib(module);
					continue;
				}
				m_driver_lib = module;
			#else
				RHIRenderer* renderer = nullptr;
			#endif

			#ifndef SQUID_EMBEDDED_RENDERER_BACKENDS
				DebugLog("RendererModule : loaded %", drivers_paths.Find(driver)->second);
			#endif

			m_chosen_driver = driver;
			m_renderer = renderer;
			break;
		}

		if(m_renderer == nullptr)
			FatalError("RendererModule : failed to load any renderer driver");

		m_renderer->LoadNewDevice({});
	}

	int RendererModule::ScoreDriver(RendererDrivers driver)
	{
		int score = -1;

		static ConstMap<std::string, RendererDrivers> cli_options = {
			{ "vulkan", RendererDrivers::Vulkan },
			{ "auto", RendererDrivers::Auto },
			{ "none", RendererDrivers::None },
		};

		static std::optional<std::string> driver_option = CommandLineInterface::Get().GetOption("renderer-backend");
		if(driver_option.has_value())
		{
			if(!cli_options.Has(*driver_option))
				Error("RendererModule : invalid render-backend option '%'", *driver_option);
			else
			{
				auto it = cli_options.Find(*driver_option);
				if(it->second != driver)
					return -1;
			}
		}

		static ConstMap<RendererDrivers, int> api_scores = {
			{ RendererDrivers::Vulkan, 500 },
			{ RendererDrivers::Auto, 0 },
			{ RendererDrivers::None, -1 },
		};

		score = api_scores.Find(driver)->second;

		if(!Application::IsInit())
			FatalError("RendererModule : cannot select renderer driver, Application is not init (wtf what did u do ?)");

		RendererDrivers preffered = Application::Get().GetEngineConfig().preffered_render_api;

		if(driver == preffered)
			score = std::numeric_limits<int>::max();

		return score;
	}

	RendererModule::~RendererModule()
	{
		MemFree(m_renderer);
		OSInstance::GetLibLoader().UnloadLib(m_driver_lib);
		s_instance = nullptr;
	}
}
