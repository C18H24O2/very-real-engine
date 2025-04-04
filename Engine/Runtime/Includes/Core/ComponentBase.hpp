#ifndef SQUID_CORE_COMPONENT_BASE_HPP__
#define SQUID_CORE_COMPONENT_BASE_HPP__

#include <Core/PreCompiled.hpp>

namespace Squid
{
	class SQUID_CORE_API ComponentBase
	{
		public:
			ComponentBase() = delete;
			ComponentBase(std::string name) : m_name(std::move(name)) {}

			virtual void OnAttach() {}
			virtual void OnUpdate(float delta) {}
			virtual void OnFixedUpdate() {}
			virtual void OnRender() {}
			virtual void OnEvent([[maybe_unused]] class Inputs& inputs) {}
			virtual void OnQuit() {}

			inline const std::string& GetName() const { return m_name; }
			virtual ~ComponentBase() = default;

		protected:
			std::string m_name;
	};
}

#endif
