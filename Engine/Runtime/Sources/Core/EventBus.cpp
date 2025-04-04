#include <Core/EventBus.hpp>
#include <Core/Logs.hpp>

namespace Squid
{
	void EventBus::Send(const std::string& listener_name, const EventBase& event)
	{
		for(const EventListener& listener : s_listeners)
		{
			if(listener.GetName() == listener_name)
			{
				listener.Call(event);
				return;
			}
		}
		Warning("Event Bus : listener not found, '%'", listener_name);
	}
}
