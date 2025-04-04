#include <Core/EventListener.hpp>

namespace Squid
{
	EventListener::EventListener(std::function<void(const EventBase&)> functor, std::string name)
	: m_listen_functor(std::move(functor)), m_name(std::move(name))
	{}
}
