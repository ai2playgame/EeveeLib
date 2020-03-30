#include "test.hpp"
#include <eevee/math/calculate/integer.hpp>

TEST_CASE("GCD AND LCM") {
	REQUIRE(eevee::gcd(12, 3) == 3);
	REQUIRE(eevee::lcm(10, 25) == 50);
	REQUIRE(eevee::gcd(12LL, 3) == 3);
	REQUIRE(eevee::lcm(10, 25LL) == 50);
}