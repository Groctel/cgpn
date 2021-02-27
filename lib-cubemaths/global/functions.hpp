#ifndef CGPN_LIB_CUBEMATH_GLOBALS
#define CGPN_LIB_CUBEMATH_GLOBALS

#include <cmath>
#include <limits>

namespace globals
{

template <typename T> inline constexpr
bool EpsilonEq (const T a, const T b) noexcept
{
	return (fabs(a - b) < std::numeric_limits<T>::epsilon());
}

} // namespace globals

#endif
