#ifndef MLK_CORE_APPLICATION_HPP__
#define MLK_CORE_APPLICATION_HPP__

#include <Core/PreCompiled.hpp>
#include <Utils/TypeList.hpp>
#include <Core/ComponentStack.hpp>
#include <Core/EngineConfig.hpp>
#include <Core/Module.hpp>

namespace Mlk
{
	class MLK_CORE_API Application : public ComponentStack
	{
		public:
			Application(const EngineConfig& config);

			void Run();

			template<typename T, typename...Args>
			void LoadEngineModule(Args&&... args);
			void ShutdownAllEngineModules();

			static inline bool IsInit() noexcept { return s_instance != nullptr; }
			static Application& Get();

			inline const EngineConfig& GetEngineConfig() const noexcept { return m_engine_config; }

			MLK_FORCEINLINE constexpr void Quit() noexcept;

			~Application();

		private:
			static Application* s_instance;
			EngineConfig m_engine_config;
			std::vector<Module*> m_modules;
			bool m_running = false;
	};
}

#include <Core/Application.inl>

#endif
