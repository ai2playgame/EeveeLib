#include "test.hpp"
#include <eevee/math/graph/WeightedUndirectedGraph.hpp>

TEST_CASE("Dijkstra") {
	eevee::WeightedUndirectedGraph graph(5);
	graph.push_edge(0, 4, 2);
	graph.push_edge(0, 1, 1);
	graph.push_edge(1, 4, 3);
	graph.push_edge(1, 2, 4);
	graph.push_edge(1, 3, 2);
	graph.push_edge(2, 3, 1);
	const auto distMap = graph.dijkstra(0);
	REQUIRE(distMap[0] == 0);
	REQUIRE(distMap[1] == 1);
	REQUIRE(distMap[2] == 4);
	REQUIRE(distMap[3] == 3);
	REQUIRE(distMap[4] == 2);
}