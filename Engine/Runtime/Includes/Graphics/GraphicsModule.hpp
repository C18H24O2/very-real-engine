#ifndef SQUID_GRAPHICS_MODULE_HPP__
#define SQUID_GRAPHICS_MODULE_HPP__

#include <Graphics/PreCompiled.hpp>
#include <Core/Module.hpp>
#include <Utils/TypeList.hpp>

namespace Squid
{
	class SQUID_GRAPHICS_API GraphicsModule : public Module
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
