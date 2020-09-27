#include <iostream>
#include <vector>
#include "bfs.hpp"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			a[u - 1].push_back(v - 1);
		}
	}
	const BFS bfs(a, 0);
	for (int i = 0; i < n; i++) cout << i + 1 << ' ' << bfs[i] << endl;
}