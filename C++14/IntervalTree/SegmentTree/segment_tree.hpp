#pragma once

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

template <typename T>
class SegmentTree {
protected:
	int _n;
	vector<T> _node;

public:
	SegmentTree(const vector<T>& a) : _n(1) {
		while (_n < static_cast<int>(a.size())) _n *= 2;
		_node.resize(2 * _n - 1, numeric_limits<T>::max());
		for (int _i = 0; _i < static_cast<int>(a.size()); _i++) _node[_n - 1 + _i] = a[_i];
		for (int _i = _n - 2; _i >= 0; _i--) _node[_i] = min(_node[2 * _i + 1], _node[2 * _i + 2]);
	}

public:
	void update(const int& index, const int& val) {
		int _i = _n - 1 + index;
		_node[_i] = val;
		while (_i > 0) {
			_i = (_i - 1) / 2;
			_node[_i] = min(_node[2 * _i + 1], _node[2 * _i + 2]);
		}
	}

public:
	T find(const int& a, const int& b) {
		return find(a, b, 0, 0, _n);
	}

protected:
	T find(const int& a, const int& b, const int& k, const int& l, const int& r) {
		if (r <= a || b <= l) return numeric_limits<T>::max();
		if (a <= l && r <= b) return _node[k];
		const T _vl = find(a, b, 2 * k + 1, l, (l + r) / 2), _vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(_vl, _vr);
	}
};