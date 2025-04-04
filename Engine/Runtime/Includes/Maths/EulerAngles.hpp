#ifndef SQUID_MATHS_EULER_ANGLES_HPP__
#define SQUID_MATHS_EULER_ANGLES_HPP__

#include <Maths/PreCompiled.hpp>

#include <Maths/Angles.hpp>

namespace Squid
{
	template<typename T>
	struct EulerAngles
	{
		constexpr EulerAngles() = default;
		constexpr EulerAngles(DegreeAngle<T> P, DegreeAngle<T> Y, DegreeAngle<T> R);
		constexpr EulerAngles(const DegreeAngle<T> angles[3]);
		template<AngleUnit Unit> constexpr EulerAngles(const Angle<Unit, T>& angle);
		constexpr EulerAngles(const Quat<T>& quat);
		template<typename U> constexpr explicit EulerAngles(const EulerAngles<U>& angles);
		constexpr EulerAngles(const EulerAngles&) = default;
		constexpr EulerAngles(EulerAngles&&) = default;
		~EulerAngles() = default;

		constexpr bool ApproxEqual(const EulerAngles& angles, T maxDifference = std::numeric_limits<T>::epsilon()) const;

		constexpr EulerAngles& Normalize();

		Quat<T> ToQuat() const;
		std::string ToString() const;

		constexpr EulerAngles operator+(const EulerAngles& angles) const;
		constexpr EulerAngles operator-(const EulerAngles& angles) const;

		constexpr EulerAngles& operator=(const EulerAngles&) = default;
		constexpr EulerAngles& operator=(EulerAngles&&) = default;

		constexpr EulerAngles& operator+=(const EulerAngles& angles);
		constexpr EulerAngles& operator-=(const EulerAngles& angles);

		constexpr bool operator==(const EulerAngles& angles) const;
		constexpr bool operator!=(const EulerAngles& angles) const;
		constexpr bool operator<(const EulerAngles& angles) const;
		constexpr bool operator<=(const EulerAngles& angles) const;
		constexpr bool operator>(const EulerAngles& angles) const;
		constexpr bool operator>=(const EulerAngles& angles) const;

		static constexpr bool ApproxEqual(const EulerAngles& lhs, const EulerAngles& rhs, T maxDifference = std::numeric_limits<T>::epsilon());
		static constexpr EulerAngles Zero();

		DegreeAngle<T> pitch, yaw, roll;
	};

	using EulerAnglesf = EulerAngles<float>;
}

#include <Maths/EulerAngles.inl>

#endif
