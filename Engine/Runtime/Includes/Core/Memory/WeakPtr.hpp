#pragma once

#include <Core/PreCompiled.hpp>

namespace Squid
{
	template <typename T>
	class WeakPtr
	{
		friend SharedPtr<T>;

		public:
			constexpr WeakPtr() noexcept = default;
			WeakPtr(const WeakPtr& rhs) noexcept;
			WeakPtr(WeakPtr&& rhs) noexcept;
			explicit WeakPtr(const SharedPtr<T>& shared) noexcept;

			inline void Reset() noexcept;
			inline void Swap(WeakPtr& rhs) noexcept;

			inline std::size_t UseCount() const noexcept;
			inline bool Expired() const noexcept;
			inline SharedPtr<T> Lock() const noexcept;

			~WeakPtr();

		private:
			struct RefCounter
			{
				T* ptr = nullptr;
				std::uint32_t count = 0;
				std::uint32_t weaks = 0;
			};

		private:
			inline void DecrementWeakCount() noexcept;

		private:
			RefCounter* m_ref = nullptr;
			T* m_ptr = nullptr;
	};
}

#include <Core/Memory/WeakPtr.inl>
