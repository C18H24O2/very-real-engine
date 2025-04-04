#ifndef SQUID_MATHS_MATHS_ENUMS_HPP__
#define SQUID_MATHS_MATHS_ENUMS_HPP__

#include <Maths/PreCompiled.hpp>

namespace Squid
{
	enum class AngleUnit
	{
		Degree = 0,
		Radian,
		Turn,

		EndEnum
	};

	constexpr std::size_t AngleUnitCount = static_cast<std::size_t>(AngleUnit::EndEnum);
}

#endif
