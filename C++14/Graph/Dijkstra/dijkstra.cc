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
	vector<bool> _c;
	vector<T> _d;

public:
	Dijkstra(const vector<vector<pair<int, T>>>& adj, const int& s) :
		_adj(adj),
		_c(adj.size()),
		_d(adj.size(), numeric_limits<T>::max())
	{
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> _pq;
		_d[s] = static_cast<T>(0);
		_pq.emplace(static_cast<T>(0), s);
		while (!_pq.empty()) {
			const pair<T, int> _f = _pq.top();
			_pq.pop();
			_c[_f.second] = true;
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