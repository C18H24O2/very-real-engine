#ifndef MLK_GRAPHICS_MODULE_HPP
#define MLK_GRAPHICS_MODULE_HPP

#include <Core/OS/LibLoader.hpp>
#include <Graphics/PreCompiled.hpp>
#include <Core/Module.hpp>
#include <Utils/TypeList.hpp>
#include <Graphics/Enums.hpp>

namespace Mlk
{
	class MLK_GRAPHICS_API GraphicsModule : public Module
	{
		public:
			using Dependencies = TypeList<class CoreModule, class RendererModule>;

			GraphicsModule();

			static inline bool IsInit() noexcept { return s_instance != nullptr; }
			static GraphicsModule& Get();

			~GraphicsModule() override;

		private:
			static GraphicsModule* s_instance;
	};
}

#endif
