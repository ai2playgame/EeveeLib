#pragma once
#include <type_traits>

namespace eevee {
template <class M, class N>
constexpr std::common_type_t<M, N> gcd(M a, N b) {
	return ((a % b == 0) ? b : gcd(b, a % b));
}
template <class M, class N>
constexpr std::common_type_t<M, N> lcm(M a, N b) {
	return a / gcd(a, b) * b;
}

}
