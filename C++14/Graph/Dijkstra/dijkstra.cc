#pragma once

#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
class Dijkstra {
protected:
	const vector<vector<pair<int, T>>>& _a;
	vector<bool> _c;
	vector<T> _d;

public:
	Dijkstra(const vector<vector<pair<int, T>>>& a, const int& s) :
		_a(a),
		_c(a.size()),
		_d(a.size(), numeric_limits<T>::max())
	{
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> _pq;

		_d[s] = static_cast<T>(0);
		_pq.emplace(static_cast<T>(0), s);
		while (!_pq.empty()) {
			const pair<T, int> _f = _pq.top();

			_pq.pop();
			_c[_f.second] = true;
			for (int i = 0; i < static_cast<int>(_a[_f.second].size()); i++) {
				if (_c[_a[_f.second][i].first]) continue;
				if (_a[_f.second][i].second + _d[_f.second] < _d[_a[_f.second][i].first]) {
					_d[_a[_f.second][i].first] = _a[_f.second][i].second + _d[_f.second];
					_pq.emplace(_d[_a[_f.second][i].first], _a[_f.second][i].first);
				}
			}
		}
	}

public:
	int operator[](const int& index) const {
		return _d[index];
	}
};