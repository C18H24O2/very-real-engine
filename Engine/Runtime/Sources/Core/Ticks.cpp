#include <Core/Ticks.hpp>

namespace Squid
{
	void Ticks::Init()
	{
		m_timer = static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
		m_ticks_before = m_timer;
		m_ticks_now = m_timer;
	}

	void Ticks::Update()
	{
		using namespace std::chrono_literals;
		m_ticks_now = static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());

		if(std::chrono::duration<std::uint64_t>{m_ticks_now - m_timer} >= 1s)
		{
			m_output_ticks = m_ticks;
			m_ticks = 0;
			m_timer = m_ticks_now;
		}

		m_ticks_elapsed_time = m_ticks_now - m_ticks_before;
		if(m_ticks_elapsed_time >= m_ns)
		{
			m_ticks++;
			m_ticks_before += m_ns;
			m_make_update = true;
		}
		else
		{
			m_make_update = false;
			std::this_thread::sleep_for(std::chrono::duration<double, std::nano>(m_ns));
		}
	}
}
