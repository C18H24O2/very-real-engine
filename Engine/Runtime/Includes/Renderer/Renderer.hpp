#ifndef MLK_RENDERER_HPP__
#define MLK_RENDERER_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef MLK_RENDERER_STATIC
	#ifdef MLK_PLAT_WINDOWS
		#ifdef MLK_COMPILER_MSVC
			#ifdef MLK_RENDERER_BUILD
				#define MLK_RENDERER_API __declspec(dllexport)
			#else
				#define MLK_RENDERER_API __declspec(dllimport)
			#endif
		#elif defined(MLK_COMPILER_GCC)
			#ifdef MLK_RENDERER_BUILD
				#define MLK_RENDERER_API __attribute__((dllexport))
			#else
				#define MLK_RENDERER_API __attribute__((dllimport))
			#endif
		#else
			#define MLK_RENDERER_API
		#endif
	#elif defined(MLK_COMPILER_GCC)
		#define MLK_RENDERER_API __attribute__((visibility("default")))
	#else
		#define MLK_RENDERER_API
	#endif
#else
	#define MLK_RENDERER_API
#endif

#endif
