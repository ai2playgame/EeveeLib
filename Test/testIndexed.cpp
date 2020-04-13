#include "test.hpp"
#include <eevee/Indexed.hpp>

TEST_CASE("test Indexed() vector") {
	std::vector<int> Vec(10, 1);
	int testIndex = 0;
	for (auto [i, thing] : eevee::Indexed(Vec)) {
		REQUIRE(testIndex == i);
		REQUIRE(thing == 1);
		testIndex++;
	}
}
