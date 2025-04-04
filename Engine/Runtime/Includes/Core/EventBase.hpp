#ifndef SQUID_CORE_BASE_EVENT_HPP__
#define SQUID_CORE_BASE_EVENT_HPP__

#include <Core/PreCompiled.hpp>

namespace Squid
{
	struct EventBase
	{
		virtual std::uint32_t What() const = 0;
	};
}

#endif
