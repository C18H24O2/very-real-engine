#ifndef MLK_RENDERER_ENUMS_HPP__
#define MLK_RENDERER_ENUMS_HPP__

#include <Renderer/PreCompiled.hpp>

namespace Mlk
{
	enum class RendererDrivers
	{
		Vulkan = 0,
		Auto,
		None,

		EndEnum
	};
	constexpr std::size_t RendererDriversCount = static_cast<std::size_t>(RendererDrivers::EndEnum);
}

#endif
