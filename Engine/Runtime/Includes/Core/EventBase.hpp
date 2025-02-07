#ifndef MLK_CORE_BASE_EVENT_HPP__
#define MLK_CORE_BASE_EVENT_HPP__

#include <Core/PreCompiled.hpp>

namespace Mlk
{
	struct EventBase
	{
		virtual std::uint32_t What() const = 0;
	};
}

#endif
