#pragma once
#include <vector>
#include <utility>
#include <queue>

namespace eevee {
// —×ÚƒŠƒXƒg‚ğg‚Á‚ÄÀ‘•
class WeightedUndirectedGraph {
public:
	WeightedUndirectedGraph(int node_size)
		: graph(node_size, std::vector<Edge>())
	{}

	void push_edge(int edge1, int edge2, int weight) {
		if (!isInGraphNode(edge1) || !isInGraphNode(edge2)) {
			return;
		}
		graph[edge1].emplace_back(edge2, weight);
		graph[edge2].emplace_back(edge1, weight);
	}

	[[nodiscard]] const auto dijkstra(int start) {
		std::vector<int> dist(graph.size());
		if (!isInGraphNode(start)) { return dist; }
		using Point = std::pair<int, int>;
		std::priority_queue < Point, std::vector<Point>, std::greater<Point>> que;
		std::fill(dist.begin(), dist.end(), INT_MAX);
		dist[start] = 0;
		que.push(Point{ 0, start });
		while (!que.empty()) {
			Point p = que.top();
			que.pop();
			int v = p.second;
			if (dist[v] < p.first) continue;
			for (const auto& e : graph[v]) {
				if (dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.push(Point{ dist[e.to], e.to });
				}
			}
		}
		return dist;
	}
private:
	struct Edge {
		int to;
		int cost;
		Edge(int t, int c) : to{ t }, cost{ c } {}
	};
	std::vector<std::vector<Edge>> graph;

	bool isInGraphNode(int node) { return node >= 0 && node < graph.size(); }
};
}


