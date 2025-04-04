#ifndef SQUID_CORE_MODULE_HPP__
#define SQUID_CORE_MODULE_HPP__

#include <Utils/NonMovable.hpp>
#include <Utils/NonCopyable.hpp>
#include <Core/PreCompiled.hpp>

namespace Squid
{
	class Module : public NonCopyable, NonMovable
	{
		public:
			virtual ~Module();

			inline const std::string& GetName() const { return m_module_name; }
			virtual void Update() {}

		protected:
			Module(std::string name);

		private:
			std::string m_module_name;
	};
}

#endif
