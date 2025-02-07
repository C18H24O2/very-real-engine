#ifndef MLK_CORE_EVENT_BUS_HPP__
#define MLK_CORE_EVENT_BUS_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/EventBase.hpp>
#include <Core/EventListener.hpp>

namespace Mlk
{
	class MLK_CORE_API EventBus
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
