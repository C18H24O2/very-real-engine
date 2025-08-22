#ifndef SQUID_CORE_EVENT_BUS_HPP__
#define SQUID_CORE_EVENT_BUS_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/EventBase.hpp>
#include <Core/EventListener.hpp>

namespace Squid
{
	template<typename T>
	class SQUID_CORE_API EventBus<T>
	{
		public:
			EventBus() = delete;
			static void Send(const std::string& listener_name, const EventBase& event);
			inline static void RegisterListener(const EventListener& listener) { s_listeners.push_back(listener); }
			~EventBus() = delete;

		private:
			inline static std::vector<EventListener> s_listeners;
	};
}

#endif
