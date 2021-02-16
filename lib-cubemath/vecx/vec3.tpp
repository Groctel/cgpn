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

	inline bool operator == (const Vec3 & other) const noexcept;
	inline bool operator != (const Vec3 & other) const noexcept;

	inline void Normalise ();
};

typedef Vec3<uint_fast8_t>  Vec3c;
typedef Vec3<double>        Vec3d;
typedef Vec3<float>         Vec3f;
typedef Vec3<int_fast32_t>  Vec3i;
typedef Vec3<uint_fast32_t> Vec3u;

/**
 * @brief Default constructor.
 */

template <typename T>
Vec3<T> :: Vec3 () noexcept
{ }

/**
 * @brief Fill constructor.
 * @param fill Element to fill the vector with.
 *
 * Constructs the vector so that every element equals the passed one.
 */

template <typename T>
inline Vec3<T> :: Vec3 (const T & fill) noexcept
{
	data[0] = fill;
	data[1] = fill;
	data[2] = fill;
}

/**
 * @brief Initialisation list constructor.
 * @param d0 First element of the newly constructed vector.
 * @param d1 Second element of the newly constructed vector.
 * @param d2 Third element of the newly constructed vector.
 */

template <typename T>
inline Vec3<T> :: Vec3 (const T & d0, const T & d1, const T & d2) noexcept
{
	data[0] = d0;
	data[1] = d1;
	data[2] = d2;
}

/**
 * @brief Copy constructor calling assignment operator.
 * @param other Vector to copy from.
 */

template <typename T>
inline Vec3<T> :: Vec3 (const Vec3<T> & other) noexcept
{
	*this = other;
}

/**
 * @brief Default destructor.
 */

template <typename T>
inline Vec3<T> :: ~Vec3 () noexcept
{ }

/**
 * @brief Dereference operator overload.
 */

template <typename T>
inline Vec3<T> :: operator T * () noexcept
{
	return data;
}

/**
 * @brief Assignment operator overload.
 * @param other Vector to assign from.
 */

template <typename T>
inline void Vec3<T> :: operator = (const Vec3<T> & other) noexcept
{
	data[0] = other.data[0];
	data[1] = other.data[1];
	data[2] = other.data[2];
}

/**
 * @brief Addition operator overload.
 * @param other Vec3 to add to the lhs one.
 */

template <typename T>
inline Vec3<T> Vec3<T> :: operator + (const Vec3<T> & other) noexcept
{
	return {
		data[0] + other.data[0],
		data[1] + other.data[1],
		data[2] + other.data[2]
	};
}

/**
 * @brief Subtraction operator overload.
 * @param other Vec3 to subtract to the lhs one.
 */

template <typename T>
inline Vec3<T> Vec3<T> :: operator - (const Vec3<T> & other) noexcept
{
	return {
		data[0] - other.data[0],
		data[1] - other.data[1],
		data[2] - other.data[2]
	};
}

/**
 * @brief Scalar product operator overload.
 * @param scalar Scalar to multiply every element of the vector with.
 */

template <typename T>
inline Vec3<T> Vec3<T> :: operator * (const T & scalar) noexcept
{
	return {
		data[0] * scalar,
		data[1] * scalar,
		data[2] * scalar
	};
}

/**
 * @brief Vector cross product operator overload.
 * @param other Vector to multiply with.
 */

template <typename T>
inline Vec3<T> Vec3<T> :: operator * (const Vec3<T> & other) noexcept
{
	return {
		data[1] * other.data[2] - data[2] * other.data[1],
		data[2] * other.data[0] - data[0] * other.data[2],
		data[0] * other.data[1] - data[1] * other.data[0]
	};
}

/**
 * @brief Scalar division operator overload.
 * @param scalar Scalar to divide every element of the vector by.
 */

template <typename T>
inline Vec3<T> Vec3<T> :: operator / (const T & scalar) noexcept
{
	return {
		data[0] / scalar,
		data[1] / scalar,
		data[2] / scalar
	};
}

/**
 * @brief Vector dot product operator overload.
 * @param other Vector to multiply with.
 */

template <typename T>
inline T Vec3<T> :: operator | (const Vec3<T> & other) noexcept
{
	return
		data[0] * other.data[0] +
		data[1] * other.data[1] +
		data[2] * other.data[2];
}

/**
 * @brief Addition assignment operator overload.
 * @param other Vec3 to add to `this`.
 */

template <typename T>
inline void Vec3<T> :: operator += (const Vec3<T> & other) noexcept
{
	*this = *this + other;
}

/**
 * @brief Subtraction assignment operator overload.
 * @param other Vec3 to subtract to `this`.
 */

template <typename T>
inline void Vec3<T> :: operator -= (const Vec3<T> & other) noexcept
{
	*this = *this - other;
}

/**
 * @brief Scalar product assignment operator overload.
 * @param other Scalar to multiplay every element of `this` with.
 */

template <typename T>
inline void Vec3<T> :: operator *= (const T & scalar) noexcept
{
	*this = *this * scalar;
}

/**
 * @brief Vector cross product assignment operator overload.
 * @param other Vector to multiply with.
 */

template <typename T>
inline void Vec3<T> :: operator *= (const Vec3<T> & other) noexcept
{
	*this = *this * other;
}

/**
 * @brief Scalar division assignment operator overload.
 * @param other Scalar to divide every element of `this` by.
 */

template <typename T>
inline void Vec3<T> :: operator /= (const T & scalar) noexcept
{
	*this = *this / scalar;
}

/**
 * @brief Equality operator overload.
 * @param other Vector to compare with.
 *
 * Behaves differently for floating point epsilon comparisons.
 */

template <typename T>
inline bool Vec3<T> :: operator == (const Vec3<T> & other) const noexcept
{
	if (std::is_same_v<T, double>)
	{
		return
			DoubleEq(data[0], other.data[0]) &&
			DoubleEq(data[1], other.data[1]) &&
			DoubleEq(data[2], other.data[2]);
	}
	else if (std::is_same_v<T, float>)
	{
		return
			FloatEq(data[0], other.data[0]) &&
			FloatEq(data[1], other.data[1]) &&
			FloatEq(data[2], other.data[2]);
	}
	else
	{
		return
			data[0] == other.data[0] &&
			data[1] == other.data[1] &&
			data[2] == other.data[2];
	}
}

/**
 * @brief Inequality operator overload calling the equality operator.
 * @param other Vector to compare with.
 */

template <typename T>
inline bool Vec3<T> :: operator != (const Vec3<T> & other) const noexcept
{
	return !(*this == other);
}

/**
 * @brief Normalises the vector in place so that it's modulus equals 1.
 * @pre `T` must be able to operate with floating point arithmetic.
 */

template <typename T>
inline void Vec3<T> :: Normalise ()
{
	T lengthSquared =
		data[0] * data[0] +
		data[1] * data[1] +
		data[2] * data[2];

	if (lengthSquared <= (T) 0.0)
		throw std::runtime_error("Illegal Vec3 normalisation lengthSquared.");

	*this *= 1.0 / sqrt(lengthSquared);
}

#endif
