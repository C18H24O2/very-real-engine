#ifndef MLK_UNIX_HPP__
#define MLK_UNIX_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef MLK_UNIX_STATIC
	#ifdef MLK_PLAT_WINDOWS
		#ifdef MLK_COMPILER_MSVC
			#ifdef MLK_UNIX_BUILD
				#define MLK_UNIX_API __declspec(dllexport)
			#else
				#define MLK_UNIX_API __declspec(dllimport)
			#endif
		#elif defined(MLK_COMPILER_GCC)
			#ifdef MLK_UNIX_BUILD
				#define MLK_UNIX_API __attribute__((dllexport))
			#else
				#define MLK_UNIX_API __attribute__((dllimport))
			#endif
		#else
			#define MLK_UNIX_API
		#endif
	#elif defined(MLK_COMPILER_GCC)
		#define MLK_UNIX_API __attribute__((visibility("default")))
	#else
		#define MLK_UNIX_API
	#endif
#else
	#define MLK_UNIX_API
#endif

#endif
