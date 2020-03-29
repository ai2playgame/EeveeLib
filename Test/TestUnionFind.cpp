#include "test.hpp"
#include <eevee/math/tree/unionFind.hpp>

TEST_CASE("union-find") {
	using namespace eevee;
	UnionFind<int> ut(5);

	ut.unite(1, 2);
	REQUIRE(ut.isSame(1, 2));
	ut.unite(3, 4);
	ut.unite(4, 0);
	ut.unite(5, -1);
	REQUIRE(ut.isSame(3, 4));
	REQUIRE(ut.isSame(4, 0));
	REQUIRE(ut.size(1) == 2);
	REQUIRE(ut.size(3) == 3);
	REQUIRE(!ut.isSame(3, 1));
}