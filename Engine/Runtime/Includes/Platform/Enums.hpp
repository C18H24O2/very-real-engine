#ifndef MLK_PLATFORM_ENUMS_HPP__
#define MLK_PLATFORM_ENUMS_HPP__

#include <Platform/PreCompiled.hpp>

namespace Mlk
{
	enum WindowStyleBits
	{
		WindowDefault = 0,
		WindowNoBorders = 1 << 0,
		WindowFullscreen = 1 << 1, // Fullscreen at creation
		WindowFullscreenDesktop = 1 << 2, // Fullscreen at desktop resolution at creation
		WindowClosable = 1 << 3,
		WindowResizable = 1 << 4,
		WindowDummy = 1 << 5, // For internal use
	};
	using WindowStyle = int;
	constexpr std::size_t WindowStyleCount = 7;
}

#endif
