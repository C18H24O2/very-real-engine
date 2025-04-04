#ifndef SQUID_CORE_EVENT_LISTENER_HPP__
#define SQUID_CORE_EVENT_LISTENER_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/EventBase.hpp>

namespace Squid
{
	class SQUID_CORE_API EventListener
	{
		public:
			EventListener() = delete;
			EventListener(std::function<void(const EventBase&)> functor, std::string name);

			inline const std::string& GetName() const { return m_name; }
			inline void Call(const EventBase& event) const noexcept { m_listen_functor(event); }

			~EventListener() = default;

		private:
			std::function<void(const EventBase&)> m_listen_functor;
			std::string m_name;
	};
}

#endif
