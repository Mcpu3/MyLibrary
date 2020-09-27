#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#include "dijkstra.hpp"
using namespace std;

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	vector<vector<pair<int, int>>> a(V);
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		a[s].emplace_back(t, d);
	}
	const Dijkstra<int> dijkstra(a, r);
	for (int i = 0; i < V; i++) {
		if (dijkstra[i] != INT_MAX) cout << dijkstra[i];
		else cout << "INF";
		cout << endl;
	}
}