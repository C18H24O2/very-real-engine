#ifndef SQUID_UTILS_BITS_ARRAY_HPP__
#define SQUID_UTILS_BITS_ARRAY_HPP__

#include <Utils/PreCompiled.hpp>
#include <Utils/NonCopyable.hpp>

namespace Squid
{
	#ifdef SQUID_64BITS
		using uintsys_t = uint64_t;
	#else
		using uintsys_t = uint32_t;
	#endif

	class BitsArray : public NonCopyable
	{
		public:
			BitsArray() = default;

			inline void Init(std::size_t bits_n);
			inline void ResetBits(bool value);
			inline void Set(std::size_t index, bool value);
			inline bool Get(std::size_t index) const;
			inline std::size_t GetFirstTrueBit();

			~BitsArray() = default;

			static constexpr uintsys_t nbits = CHAR_BIT * sizeof(uintsys_t);

		private:
			std::unique_ptr<uintsys_t[]> m_pool;
			std::size_t m_size = 0;
	};
}

#include <Utils/BitsArray.inl>

#endif
