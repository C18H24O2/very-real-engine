#ifndef MLK_CORE_TICKS_HPP__
#define MLK_CORE_TICKS_HPP__

#include <Core/PreCompiled.hpp>

namespace Mlk
{
	class MLK_CORE_API Ticks
	{
		friend class Application;
		friend class CoreModule;

		public:
			Ticks() = default;

			inline void SetTicksGoal(std::uint32_t ticks) noexcept { m_ticks_goal = ticks; m_ns = 1'000'000'000.0 / m_ticks_goal; }
			inline std::uint32_t GetTicks() const noexcept { return m_output_ticks; }
			inline std::uint32_t GetTicksGoal() const noexcept { return m_ticks_goal; }

			~Ticks() = default;	

		private:
			void Init();
			inline bool ShouldMakeUpdate() const noexcept { return m_make_update; }
			void Update();

		private:
			int m_output_ticks = 0;
			std::uint32_t m_ticks_goal = 60;
			double m_ns = 1'000'000'000.0 / static_cast<double>(m_ticks_goal);
			std::int64_t m_timer = 0;
			std::int64_t m_ticks_before = 0;
			std::int64_t m_ticks_now = 0;
			std::uint32_t m_ticks_elapsed_time = 0;
			std::uint32_t m_ticks = 0;
			bool m_make_update = false;
	};
}

#endif
