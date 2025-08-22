#pragma once
#include <Core/ComponentStack.hpp>

namespace Squid
{
	template<typename T, typename ... Args>
	T& ComponentStack::AddComponent(Args&& ... args)
	{
		return static_cast<T&>(AddComponent(MemAlloc<T>(std::forward<Args>(args)...)));
	}

	ComponentBase* ComponentStack::GetComponent(std::size_t index)
	{
		return index < m_components.size() ? m_components[index] : nullptr;
	}

	template<typename T>
	T& ComponentStack::GetComponentAs(const std::string& name)
	{
		static_assert(!std::is_pointer_v<T>, "Components can not be casted to pointers");
		return static_cast<T>(GetComponent(name));
	}
	
	template<typename T>
	T& ComponentStack::GetComponentAs(std::size_t index)
	{
		static_assert(!std::is_pointer_v<T>, "Components can not be casted to pointers");
		return static_cast<T>(GetComponent(index));
	}

	template<typename T>
	T& ComponentStack::GetComponent()
	{
		static_assert(!std::is_pointer_v<T>, "Components can not be casted to pointers");
		for (auto& component : m_components)
		{
			if (auto casted = dynamic_cast<T*>(component))
				return *casted;
		}
		return nullptr;
	}
}
