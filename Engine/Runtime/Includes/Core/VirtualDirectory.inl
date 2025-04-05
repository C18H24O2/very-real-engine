#pragma once
#include <Core/VirtualDirectory.hpp>

namespace Squid
{
	template <typename F>
	void VirtualDirectory::ForEachEntries(F&& f)
	{
		static_assert(std::is_invocable_v<F(const Entry)>, "Squid::VirtualDirectory::ForEachEntries given callback is invalid");
		for(auto&& entry : m_entries)
			f(std::as_const(entry));
	}
}
