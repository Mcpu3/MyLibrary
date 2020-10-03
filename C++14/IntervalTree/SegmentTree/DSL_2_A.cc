#include <climits>
#include <iostream>
#include <vector>
#include "segment_tree.hpp"
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	SegmentTree<int> segment_tree(vector<int>(n, INT_MAX));
	for (int i = 0; i < q; i++) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0) segment_tree.update(x, y);
		else cout << segment_tree.find(x, y + 1) << endl;
	}
}