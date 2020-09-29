#pragma once

#include <utility>
#include <vector>
using namespace std;

class DSU {
protected:
	vector<int> _par;

public:
	DSU(const int& n) : _par(n, -1) {}

public:
	bool is_same(const int& a, const int& b) {
		return root(a) == root(b);
	}

public:
	void unite(const int& a, const int& b) {
		if (is_same(a, b)) return;
		int _a = root(a), _b = root(b);
		if (size(_a) < size(_b)) swap(_a, _b);
		_par[_a] += _par[_b];
		_par[_b] = _a;
	}

public:
	int root(const int& a) {
		if (_par[a] < 0) return a;
		_par[a] = root(_par[a]);
		return _par[a];
	}

public:
	int size(const int& a) {
		return -_par[root(a)];
	}
};