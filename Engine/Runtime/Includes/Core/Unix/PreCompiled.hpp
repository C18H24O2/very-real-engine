#ifndef SQUID_DRIVERS_UNIX_PRE_COMPILED_HEADER_HPP__
#define SQUID_DRIVERS_UNIX_PRE_COMPILED_HEADER_HPP__

#include <Core/CompilationProfile.hpp>
#include <Core/Unix/Unix.hpp>
#include <ctime>

#ifdef SQUID_PLAT_UNIX
	#include <unistd.h>
	#include <signal.h>
	#include <dlfcn.h>
#endif

#endif
