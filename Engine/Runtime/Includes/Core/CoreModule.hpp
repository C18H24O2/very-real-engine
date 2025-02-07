#ifndef MLK_CORE_COREMODULE_HPP__
#define MLK_CORE_COREMODULE_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/Module.hpp>
#include <Core/Ticks.hpp>
#include <Utils/TypeList.hpp>

namespace Mlk
{
	class MLK_CORE_API CoreModule : public Module
	{
		public:
			using Dependencies = TypeList<>;

			CoreModule();

			static inline bool IsInit() noexcept { return s_instance != nullptr; }
			static CoreModule& Get();

			inline Ticks& GetTicksReference() { return m_ticks; }

			~CoreModule() override;

		private:
			static CoreModule* s_instance;
			Ticks m_ticks;
	};
}

#endif
