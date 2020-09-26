#include <iostream>
#include "bfs.cc"
using namespace std;

int main() {
	vector<vector<int>> a{ { 1, 2 }, { 0, 3 }, { 0 }, { 1 } };
	vector<BFS> bfs{ { a, 0 }, { a, 1 }, { a, 2 }, { a, 3 } };

	cout << bfs[0][0] << endl;
	cout << bfs[1][2] << endl;
	cout << bfs[2][1] << endl;
	cout << bfs[3][2] << endl;
}