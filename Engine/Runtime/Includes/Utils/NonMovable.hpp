#ifndef SQUID_UTILS_NON_MOVABLE_HPP__
#define SQUID_UTILS_NON_MOVABLE_HPP__

namespace Squid
{
	class NonMovable
	{
		protected:
			NonMovable() = default;
			virtual ~NonMovable() = default;

		public:
			NonMovable(const NonMovable&) = default;
			NonMovable(NonMovable&&) noexcept = delete;
			NonMovable& operator=(const NonMovable&) = default;
			NonMovable& operator=(NonMovable&&) noexcept = delete;
	};
}

#endif
