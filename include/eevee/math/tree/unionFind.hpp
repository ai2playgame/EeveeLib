#pragma once

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cstdint>

namespace eevee {
template <typename T = int>
class UnionFind {
public:
	UnionFind(T n) 
		: _par( n )
		, _size( n, T{1} ){
		for (int i = 0; i < n; i++) {
			_par[i] = i;
		}
	}
	bool unite(T x, T y) {
		if (x < 0 || x >= _size.size() || y < 0 || y >= _size.size()) {
			return false;
		}
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (_size[x] == _size[y]) {
			std::swap(x, y);
		}
		_size[x] += _size[y];
		_par[y] = x;

		return true;
	}

	[[nodiscard]] bool isSame(T x, T y) { 
		if (x < 0 || x >= _size.size() || y < 0 || y >= _size.size()) {
			return false;
		}
		return root(x) == root(y); 
	}
	
	[[nodiscard]] T size(T x) { 
		if (x < 0 || x >= _size.size()) {
			return false;
		}
		return _size[root(x)]; 
	}

private:
	std::vector<T> _par, _size;

	T root(T x) {
		if (_par[x] == x) {
			return x;
		}
		else {
			return _par[x] = root(_par[x]); // shrink edges
		}
	}
};
}
