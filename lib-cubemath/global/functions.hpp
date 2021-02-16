#ifndef CGPN_LIB_CUBEMATH_GLOBALS
#define CGPN_LIB_CUBEMATH_GLOBALS

#include <cmath>
#include <limits>

/**
 * @brief Safely compares two double precission floating point numbers.
 * @param a First double to compare.
 * @param b Second double to compare.
 */

inline bool DoubleEq (const double a, const double b)
{
	return (fabs(a - b) < std::numeric_limits<float>::epsilon());
}

/**
 * @brief Safely compares two floating point numbers.
 * @param a First float to compare.
 * @param b Second float to compare.
 */

inline bool FloatEq (const float a, const float b)
{
	return (fabs(a - b) < std::numeric_limits<float>::epsilon());
}

#endif
