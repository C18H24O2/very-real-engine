#ifndef MLK_CORE_HPP__
#define MLK_CORE_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef MLK_CORE_STATIC
	#ifdef MLK_PLAT_WINDOWS
		#ifdef MLK_COMPILER_MSVC
			#ifdef MLK_CORE_BUILD
				#define MLK_CORE_API __declspec(dllexport)
			#else
				#define MLK_CORE_API __declspec(dllimport)
			#endif
		#elif defined(MLK_COMPILER_GCC)
			#ifdef MLK_CORE_BUILD
				#define MLK_CORE_API __attribute__((dllexport))
			#else
				#define MLK_CORE_API __attribute__((dllimport))
			#endif
		#else
			#define MLK_CORE_API
		#endif
	#elif defined(MLK_COMPILER_GCC)
		#define MLK_CORE_API __attribute__((visibility("default")))
	#else
		#define MLK_CORE_API
	#endif
#else
	#define MLK_CORE_API
#endif

#endif
