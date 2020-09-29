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
	const vector<vector<pair<int, T>>>& _adj;
	vector<T> _d;

public:
	Dijkstra(const vector<vector<pair<int, T>>>& adj, const int& s) :
		_adj(adj),
		_d(adj.size(), numeric_limits<T>::max())
	{
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> _pq;
		vector<bool> _c(adj.size());
		_d[s] = 0;
		_pq.emplace(0, s);
		while (!_pq.empty()) {
			const pair<T, int> _f = _pq.top();
			_pq.pop();
			_c[_f.second] = true;
			if (_d[_f.second] < _f.first) continue;
			for (int _i = 0; _i < static_cast<int>(_adj[_f.second].size()); _i++) {
				if (_c[_adj[_f.second][_i].first]) continue;
				if (_d[_adj[_f.second][_i].first] > _d[_f.second] + _adj[_f.second][_i].second) {
					_d[_adj[_f.second][_i].first] = _d[_f.second] + _adj[_f.second][_i].second;
					_pq.emplace(_d[_adj[_f.second][_i].first], _adj[_f.second][_i].first);
				}
			}
		}
	}

public:
	int operator[](const int& index) const {
		return _d[index];
	}
};