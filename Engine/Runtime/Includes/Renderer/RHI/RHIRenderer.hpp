#ifndef MLK_RHI_RENDERER_HPP__
#define MLK_RHI_RENDERER_HPP__

#include <Renderer/PreCompiled.hpp>
#include <Renderer/RHI/Defs.hpp>

namespace Mlk
{
	class MLK_RENDERER_API RHIRenderer
	{
		public:
			RHIRenderer() = default;

			virtual std::uint32_t LoadNewDevice(const PhysicalDeviceMinimalSpecs& specs) noexcept = 0;
			virtual class RHIDevice& GetDevice(std::uint32_t index) = 0;

			virtual ~RHIRenderer() = default;
	};
}

#endif 
