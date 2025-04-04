#include <Core/Module.hpp>
#include <Core/Logs.hpp>

namespace Squid
{
	Module::Module(std::string name) : m_module_name(std::move(name))
	{
		DebugLog("Starting %...", m_module_name);
	}

	Module::~Module()
	{
		DebugLog("Shutdown %",  m_module_name);
	}
}
