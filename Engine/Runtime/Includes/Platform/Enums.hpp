#ifndef SQUID_PLATFORM_ENUMS_HPP__
#define SQUID_PLATFORM_ENUMS_HPP__

#include <Platform/PreCompiled.hpp>

namespace Squid
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
