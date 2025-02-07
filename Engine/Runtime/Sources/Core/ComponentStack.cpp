#include <Core/Logs.hpp>
#include <Core/ComponentStack.hpp>
#include <Core/Memory/JamAllocator.hpp>
#include <Core/Memory/FixedAllocator.hpp>

namespace Mlk
{
	ComponentBase& ComponentStack::AddComponent(ComponentBase* component)
	{
		m_components.push_back(component);
		component->OnAttach();
		return *component;
	}

	void ComponentStack::RemoveComponent(ComponentBase* component)
	{
		auto it = std::find(m_components.cbegin(), m_components.cend(), component);
		if(it != m_components.cend())
		{
			(*it)->OnQuit();
			m_components.erase(it);
		}
	}

	void ComponentStack::RemoveComponent(const std::string& name)
	{
		for(std::size_t i = 0; i < m_components.size(); i++)
		{
			if(m_components[i]->GetName() == name)
			{
				m_components[i]->OnQuit();
				m_components.erase(m_components.begin() + i);
				break;
			}
		}
	}

	ComponentBase* ComponentStack::GetComponent(const std::string& name)
	{
		auto it = std::find_if(m_components.begin(), m_components.end(), [=](ComponentBase* c) { return c->GetName() == name; });
		if(it != m_components.end())
			return *it;
		return nullptr;
	}

	void ComponentStack::Destroy()
	{
		for(ComponentBase* elem : m_components)
		{
			bool has_been_freed = false;
			for(auto& jam : Memory::Internal::GetControlUnit()->jam_stack)
			{
				if(!jam.second)
					continue;
				if(jam.first->Contains(elem))
				{
					jam.first->Free(elem);
					has_been_freed = true;
					break;
				}
			}
			if(!has_been_freed)
			{
				for(auto& fixed : Memory::Internal::GetControlUnit()->fixed_stack)
				{
					if(!fixed.second)
						continue;
					if(fixed.first->Contains(elem))
					{
						fixed.first->Free(elem);
						has_been_freed = true;
						break;
					}
				}
			}
			if(!has_been_freed)
			{
				Warning("Component Stack: unable to free a component \"%\" address(%), unable to find its allocator", elem->GetName(), elem);
				elem->~ComponentBase();
			}
		}
	}
}
