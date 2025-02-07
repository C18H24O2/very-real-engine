#ifndef MLK_RENDERER_MODULE_HPP__
#define MLK_RENDERER_MODULE_HPP__

#include <Core/OS/LibLoader.hpp>
#include <Renderer/PreCompiled.hpp>
#include <Core/Module.hpp>
#include <Utils/TypeList.hpp>
#include <Renderer/Enums.hpp>
#include <Renderer/RHI/RHIRenderer.hpp>

namespace Mlk
{
	class MLK_RENDERER_API RendererModule : public Module
	{
		public:
			using Dependencies = TypeList<>;

			RendererModule();

			static inline bool IsInit() noexcept { return s_instance != nullptr; }
			static RendererModule& Get();

			inline RHIRenderer& GetRenderer() noexcept { return *m_renderer; }
			inline RendererDrivers GetChosenRendererDrivers() const noexcept { return m_chosen_driver; }

			~RendererModule() override;

		private:
			void LoadDriver();
			int ScoreDriver(RendererDrivers driver);

		private:
			static RendererModule* s_instance;
			RendererDrivers m_chosen_driver = RendererDrivers::None;
			RHIRenderer* m_renderer = nullptr;
			LibModule m_driver_lib = NullModule;
	};
}

#endif
