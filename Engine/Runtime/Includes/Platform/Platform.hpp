#ifndef SQUID_PLATFORM_HPP__
#define SQUID_PLATFORM_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef SQUID_PLATFORM_STATIC
	#ifdef SQUID_PLAT_WINDOWS
		#ifdef SQUID_COMPILER_MSVC
			#ifdef SQUID_PLATFORM_BUILD
				#define SQUID_PLATFORM_API __declspec(dllexport)
			#else
				#define SQUID_PLATFORM_API __declspec(dllimport)
			#endif
		#elif defined(SQUID_COMPILER_GCC)
			#ifdef SQUID_PLATFORM_BUILD
				#define SQUID_PLATFORM_API __attribute__((dllexport))
			#else
				#define SQUID_PLATFORM_API __attribute__((dllimport))
			#endif
		#else
			#define SQUID_PLATFORM_API
		#endif
	#elif defined(SQUID_COMPILER_GCC)
		#define SQUID_PLATFORM_API __attribute__((visibility("default")))
	#else
		#define SQUID_PLATFORM_API
	#endif
#else
	#define SQUID_PLATFORM_API
#endif

#endif
