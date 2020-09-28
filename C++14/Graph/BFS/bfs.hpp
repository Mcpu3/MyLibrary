#pragma once

#include <queue>
#include <vector>
using namespace std;

class BFS {
protected:
	const vector<vector<int>>& _adj;
	vector<int> _d;

public:
	BFS(const vector<vector<int>>& adj, const int& s) :
		_adj(adj),
		_d(adj.size(), -1)
	{
		queue<int> _q;
		_q.push(s);
		_d[s] = 0;
		while (!_q.empty()) {
			for (const int& _i : _adj[_q.front()]) {
				if (_d[_i] != -1) continue;
				_d[_i] = _d[_q.front()] + 1;
				_q.push(_i);
			}
			_q.pop();
		}
	}

public:
	int operator[](const int& index) const {
		return _d[index];
	}
};