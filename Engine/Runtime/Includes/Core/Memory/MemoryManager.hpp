#pragma once

#include <Core/Core.hpp>
#include <Core/PreCompiled.hpp>

namespace Mlk
{
	class JamAllocator;
	class FixedAllocator;

	namespace Memory::Internal
	{
		struct MLK_CORE_API ControlUnit
		{
			std::vector<std::pair<JamAllocator*, bool>> jam_stack;
			std::vector<std::pair<FixedAllocator*, bool>> fixed_stack;
		};
		MLK_CORE_API void* Alloc(std::size_t size, bool is_class);
		MLK_CORE_API std::shared_ptr<ControlUnit> GetControlUnit();
		MLK_CORE_API void Dealloc(void* ptr);
	}

	template<typename T, typename ... Args>
	inline T* MemAlloc(Args&& ... args);

	template<typename T = void>
	inline T* MemAllocSize(std::size_t size);

	template<typename T>
	inline void MemFree(T* ptr);
}

#include <Core/Memory/MemoryManager.inl>
