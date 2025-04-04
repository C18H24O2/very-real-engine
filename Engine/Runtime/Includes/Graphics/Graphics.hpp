#ifndef SQUID_GRAPHICS_HPP__
#define SQUID_GRAPHICS_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef SQUID_GRAPHICS_STATIC
	#ifdef SQUID_PLAT_WINDOWS
		#ifdef SQUID_COMPILER_MSVC
			#ifdef SQUID_GRAPHICS_BUILD
				#define SQUID_GRAPHICS_API __declspec(dllexport)
			#else
				#define SQUID_GRAPHICS_API __declspec(dllimport)
			#endif
		#elif defined(SQUID_COMPILER_GCC)
			#ifdef SQUID_GRAPHICS_BUILD
				#define SQUID_GRAPHICS_API __attribute__((dllexport))
			#else
				#define SQUID_GRAPHICS_API __attribute__((dllimport))
			#endif
		#else
			#define SQUID_GRAPHICS_API
		#endif
	#elif defined(SQUID_COMPILER_GCC)
		#define SQUID_GRAPHICS_API __attribute__((visibility("default")))
	#else
		#define SQUID_GRAPHICS_API
	#endif
#else
	#define SQUID_GRAPHICS_API
#endif

#endif
