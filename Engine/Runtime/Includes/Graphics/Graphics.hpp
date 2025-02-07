#ifndef MLK_GRAPHICS_HPP__
#define MLK_GRAPHICS_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef MLK_GRAPHICS_STATIC
	#ifdef MLK_PLAT_WINDOWS
		#ifdef MLK_COMPILER_MSVC
			#ifdef MLK_GRAPHICS_BUILD
				#define MLK_GRAPHICS_API __declspec(dllexport)
			#else
				#define MLK_GRAPHICS_API __declspec(dllimport)
			#endif
		#elif defined(MLK_COMPILER_GCC)
			#ifdef MLK_GRAPHICS_BUILD
				#define MLK_GRAPHICS_API __attribute__((dllexport))
			#else
				#define MLK_GRAPHICS_API __attribute__((dllimport))
			#endif
		#else
			#define MLK_GRAPHICS_API
		#endif
	#elif defined(MLK_COMPILER_GCC)
		#define MLK_GRAPHICS_API __attribute__((visibility("default")))
	#else
		#define MLK_GRAPHICS_API
	#endif
#else
	#define MLK_GRAPHICS_API
#endif

#endif
