#pragma once

#include <vector>
using namespace std;

template <typename T>
class BinarySearch {
public:
	static int binary_search(const vector<T>& a, const T& key, bool (*is_ok)(const vector<T>& a, const T& key, const int& mid)) {
		int _ng = -1, _ok = a.size();
		while (abs(_ng - _ok) > 1) {
			const int _mid = (_ng + _ok) / 2;
			if (is_ok(a, key, _mid)) _ok = _mid;
			else _ng = _mid;
		}
		return _ok;
	}
};