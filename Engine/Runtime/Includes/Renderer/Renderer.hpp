#ifndef SQUID_RENDERER_HPP__
#define SQUID_RENDERER_HPP__

#include <Core/CompilationProfile.hpp>

#ifndef SQUID_RENDERER_STATIC
	#ifdef SQUID_PLAT_WINDOWS
		#ifdef SQUID_COMPILER_MSVC
			#ifdef SQUID_RENDERER_BUILD
				#define SQUID_RENDERER_API __declspec(dllexport)
			#else
				#define SQUID_RENDERER_API __declspec(dllimport)
			#endif
		#elif defined(SQUID_COMPILER_GCC)
			#ifdef SQUID_RENDERER_BUILD
				#define SQUID_RENDERER_API __attribute__((dllexport))
			#else
				#define SQUID_RENDERER_API __attribute__((dllimport))
			#endif
		#else
			#define SQUID_RENDERER_API
		#endif
	#elif defined(SQUID_COMPILER_GCC)
		#define SQUID_RENDERER_API __attribute__((visibility("default")))
	#else
		#define SQUID_RENDERER_API
	#endif
#else
	#define SQUID_RENDERER_API
#endif

#endif
