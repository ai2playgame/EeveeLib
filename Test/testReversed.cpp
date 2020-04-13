#include "test.hpp"
#include <eevee/Reversed.hpp>
#include <iostream>
#include <forward_list>

TEST_CASE("test Reversed vector") {
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	int testcase = 6;
	for (auto thing : eevee::Reversed(vec)) {
		REQUIRE(testcase == thing);
		testcase--;
	}
	REQUIRE(testcase == 0);
}
