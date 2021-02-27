/** @file vecx/vec3.tpp
 */

#ifndef CGPN_LIB_CUBEMATH_VEC3
#define CGPN_LIB_CUBEMATH_VEC3

#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include "global/functions.hpp"

/** @class Vec3
 *
 * @brief Vector (or tuple) that consists of exactly 3 elements of any type.
 */

template <typename T>
class Vec3
{
private:
	T data[3] = {0};

public:
	inline  Vec3 () noexcept;
	inline  Vec3 (const T & fill) noexcept;
	inline  Vec3 (const T * elements) noexcept;
	inline  Vec3 (const T & d0, const T & d1, const T & d2) noexcept;
	inline  Vec3 (const Vec3 & other) noexcept;
	inline ~Vec3 () noexcept;

	inline operator T * () noexcept;

	inline void operator = (const Vec3 & other) noexcept;
	inline Vec3 operator + (const Vec3 & other) noexcept;
	inline Vec3 operator - (const Vec3 & other) noexcept;
	inline Vec3 operator * (const T & scalar)   noexcept;
	inline Vec3 operator * (const Vec3 & other) noexcept;
	inline Vec3 operator / (const T & scalar)   noexcept;
	inline T    operator | (const Vec3 & other) noexcept;

	inline void operator += (const Vec3 & other) noexcept;
	inline void operator -= (const Vec3 & other) noexcept;
	inline void operator *= (const T & scalar)   noexcept;
	inline void operator *= (const Vec3 & other) noexcept;
	inline void operator /= (const T & scalar)   noexcept;

	inline constexpr bool operator == (const Vec3 & other) const noexcept;
	inline constexpr bool operator != (const Vec3 & other) const noexcept;
	inline constexpr bool EpsilonEq   (const Vec3 & other) const noexcept;

	inline void Normalise () noexcept;
};

typedef Vec3<uint_fast8_t>  Vec3c;
typedef Vec3<double>        Vec3d;
typedef Vec3<float>         Vec3f;
typedef Vec3<int_fast32_t>  Vec3i;
typedef Vec3<uint_fast32_t> Vec3u;

template <typename T>
Vec3<T> :: Vec3 () noexcept
{ }

template <typename T> inline
Vec3<T> :: Vec3 (const T & fill) noexcept
{
	data[0] = fill;
	data[1] = fill;
	data[2] = fill;
}

template <typename T> inline
Vec3<T> :: Vec3 (const T & d0, const T & d1, const T & d2) noexcept
{
	data[0] = d0;
	data[1] = d1;
	data[2] = d2;
}

template <typename T> inline
Vec3<T> :: Vec3 (const Vec3<T> & other) noexcept
{
	*this = other;
}

template <typename T> inline
Vec3<T> :: ~Vec3 () noexcept
{ }

/**
 * Allows for the user to access the vector with the `[]` operator. Accessing
 * legal values is the user's responsibility.
 */

template <typename T> inline
Vec3<T> :: operator T * () noexcept
{
	return data;
}

template <typename T> inline
void Vec3<T> :: operator = (const Vec3<T> & other) noexcept
{
	data[0] = other.data[0];
	data[1] = other.data[1];
	data[2] = other.data[2];
}

template <typename T> inline
Vec3<T> Vec3<T> :: operator + (const Vec3<T> & other) noexcept
{
	return Vec3<T>(
		data[0] + other.data[0],
		data[1] + other.data[1],
		data[2] + other.data[2]
	);
}

template <typename T> inline
Vec3<T> Vec3<T> :: operator - (const Vec3<T> & other) noexcept
{
	return Vec3<T>(
		data[0] - other.data[0],
		data[1] - other.data[1],
		data[2] - other.data[2]
	);
}

template <typename T> inline
Vec3<T> Vec3<T> :: operator * (const T & scalar) noexcept
{
	return Vec3<T>(
		data[0] * scalar,
		data[1] * scalar,
		data[2] * scalar
	);
}

template <typename T> inline
Vec3<T> Vec3<T> :: operator * (const Vec3<T> & other) noexcept
{
	return Vec3<T>(
		data[1] * other.data[2] - data[2] * other.data[1],
		data[2] * other.data[0] - data[0] * other.data[2],
		data[0] * other.data[1] - data[1] * other.data[0]
	);
}

template <typename T> inline
Vec3<T> Vec3<T> :: operator / (const T & scalar) noexcept
{
	return Vec3<T>(
		data[0] / scalar,
		data[1] / scalar,
		data[2] / scalar
	);
}

template <typename T> inline
T Vec3<T> :: operator | (const Vec3<T> & other) noexcept
{
	return
		data[0] * other.data[0] +
		data[1] * other.data[1] +
		data[2] * other.data[2];
}

template <typename T> inline
void Vec3<T> :: operator += (const Vec3<T> & other) noexcept
{
	*this = *this + other;
}

template <typename T> inline
void Vec3<T> :: operator -= (const Vec3<T> & other) noexcept
{
	*this = *this - other;
}

template <typename T> inline
void Vec3<T> :: operator *= (const T & scalar) noexcept
{
	*this = *this * scalar;
}

template <typename T> inline
void Vec3<T> :: operator *= (const Vec3<T> & other) noexcept
{
	*this = *this * other;
}

template <typename T> inline
void Vec3<T> :: operator /= (const T & scalar) noexcept
{
	*this = *this / scalar;
}

template <typename T> inline constexpr
bool Vec3<T> :: operator == (const Vec3<T> & other) const noexcept
{
	return
		data[0] == other.data[0] &&
		data[1] == other.data[1] &&
		data[2] == other.data[2];
}

/**
 * This function is preferred when comparing floating point numbers because
 * overloading `==` with epsilon comparison violates the transitive property.
 */

template <typename T> inline constexpr
bool Vec3<T> :: EpsilonEq (const Vec3<T> & other) const noexcept
{
	return
		globals::EpsilonEq(data[0], other.data[0]) &&
		globals::EpsilonEq(data[1], other.data[1]) &&
		globals::EpsilonEq(data[2], other.data[2]);
}

template <typename T> inline constexpr
bool Vec3<T> :: operator != (const Vec3<T> & other) const noexcept
{
	return !(*this == other);
}

/**
 * `T` must be able to operate with floating point arithmetic. It is also the
 * user's responsibility to ensure that the vector's squared length is greater
 * than 0.
 */

template <typename T> inline
void Vec3<T> :: Normalise () noexcept
{
	T lengthSquared =
		data[0] * data[0] +
		data[1] * data[1] +
		data[2] * data[2];

	*this *= 1.0 / sqrt(lengthSquared);
}

#endif
