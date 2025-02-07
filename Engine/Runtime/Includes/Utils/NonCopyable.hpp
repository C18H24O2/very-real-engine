#ifndef MLK_UTILS_NON_COPYABLE_HPP__
#define MLK_UTILS_NON_COPYABLE_HPP__

namespace Mlk
{
	class NonCopyable
	{
		protected:
			NonCopyable() = default;
			virtual ~NonCopyable() = default;

		public:
			NonCopyable(const NonCopyable&) = delete;
			NonCopyable(NonCopyable&&) noexcept = default;
			NonCopyable& operator=(const NonCopyable&) = delete;
			NonCopyable& operator=(NonCopyable&&) noexcept = default;
	};
}

#endif
