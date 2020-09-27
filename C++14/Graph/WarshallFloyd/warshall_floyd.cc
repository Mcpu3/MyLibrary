#pragma once

#include <algorithm>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
class WarshallFloyd {
protected:
	const vector<vector<pair<int, T>>> _adj;
	vector<vector<T>> _d;

protected:
	inline void to_adj() {
		for (int i = 0; i < static_cast<int>(_adj.size()); i++) {
			_d[i][i] = static_cast<T>(0);
			for (const pair<int, T>& j : _adj[i]) _d[i][j.first] = j.second;
		}
	}

public:
	WarshallFloyd(const vector<vector<pair<int, T>>>& m) :
		_adj(m),
		_d(m.size(), vector<T>(m.size(), numeric_limits<T>::max()))
	{
		to_adj();
		for (int k = 0; k < static_cast<T>(_d.size()); k++) {
			for (int i = 0; i < static_cast<T>(_d.size()); i++) {
				if (_d[i][k] == numeric_limits<T>::max()) continue;
				for (int j = 0; j < static_cast<T>(_d.size()); j++) {
					if (_d[k][j] == numeric_limits<T>::max()) continue;
					_d[i][j] = min(_d[i][j], _d[i][k] + _d[k][j]);
				}
			}
		}
	}

public:
	bool has_negative_cycle() {
		bool has_negative_cycle = false;

		for (int i = 0; i < static_cast<int>(_d.size()); i++) {
			if (_d[i][i] < 0) {
				has_negative_cycle = true;
				break;
			}
		}
		return has_negative_cycle;
	}

public:
	int operator()(const int& i, const int& j) const {
		return _d[i][j];
	}
};