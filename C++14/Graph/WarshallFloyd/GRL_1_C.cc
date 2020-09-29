#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#include "warshall_floyd.hpp"
using namespace std;

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<pair<int, int>>> a(V);
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		a[s].emplace_back(t, d);
	}
	WarshallFloyd<int> warshall_floyd(a);
	if (warshall_floyd.has_negative_cycle()) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V - 1; j++) {
			if (warshall_floyd(i, j) != INT_MAX) cout << warshall_floyd(i, j);
			else cout << "INF";
			cout << ' ';
		}
		if (warshall_floyd(i, V - 1) != INT_MAX) cout << warshall_floyd(i, V - 1);
		else cout << "INF";
		cout << endl;
	}
}