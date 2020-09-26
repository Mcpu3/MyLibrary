#pragma once

#include <queue>
#include <vector>
using namespace std;

class BFS {
protected:
	const vector<vector<int>>& _a;
	vector<int> _d;

public:
	BFS(const vector<vector<int>>& a, const int& s) :
		_a(a),
		_d(a.size(), -1)
	{
		queue<int> _q;

		_d[s] = 0;
		_q.push(s);
		while (!_q.empty()) {
			for (const int& _i : _a[_q.front()]) {
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