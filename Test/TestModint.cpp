#include "test.hpp"
#include <eevee/math/modint/modint.hpp>

TEST_CASE("ModInt Initialization"){
	using namespace eevee;
	ModInt<100> m1{}, m2{ 90 }, m3{ 101 };
	REQUIRE(m1.value() == 0);
	REQUIRE(m1.getMod() == 100);
	REQUIRE(m2.value() == 90);
	REQUIRE(m3.value() == 1);
}

TEST_CASE("ModInt inverse()") {
	using M13 = eevee::ModInt<13>;
	REQUIRE(M13{ 1 }.inverse().value() == 1);
	REQUIRE(M13{ 2 }.inverse().value() == 7);
	REQUIRE(M13{ 3 }.inverse().value() == 9);
	REQUIRE(M13{ 4 }.inverse().value() == 10);
	REQUIRE(M13{ 5 }.inverse().value() == 8);
	REQUIRE(M13{ 6 }.inverse().value() == 11);
}

TEST_CASE("ModInt arithmetic operation") {
	using namespace eevee;
	ModInt<100> m1{ 10 }, m2{ 90 };
	REQUIRE((m1 + m2).value() == 0);
	REQUIRE((m2 - m1).value() == 80);
	REQUIRE((m1 * m2).value() == 0);

	using M13 = ModInt<13>;
	REQUIRE(M13{ 1 } / M13{ 5 }.value() == 8);

	REQUIRE(ModInt<4>(15).pow(10).value() == 1);
	ModInt<4> m3{ 15 };
	m3 ^ 10;
	REQUIRE(m3.value() == 1);
}

TEST_CASE("ModInt Comparison operator") {
	using M13 = eevee::ModInt<13>;
	REQUIRE(M13{ 1 } == M13{ 14 });
	REQUIRE(M13{ 12 } == M13{ -1 });
	REQUIRE(M13{ 12 } != M13{ 1 });
}