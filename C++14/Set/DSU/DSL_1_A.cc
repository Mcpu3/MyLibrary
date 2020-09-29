#include <iostream>
#include "dsu.hpp"
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	for (int i = 0; i < q; i++) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0) dsu.unite(x, y);
		else cout << dsu.is_same(x, y) << endl;
	}
}