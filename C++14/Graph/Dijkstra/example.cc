#include <iostream>
#include "dijkstra.cc"
using namespace std;

int main() {
	vector<vector<pair<int, int>>> a{
		{ { 1, 2 }, { 2, 3 } },
		{ { 0, 5 }, { 3, 7 } },
		{ { 0, 11 } },
		{ { 1, 13 } }
	};
	vector<Dijkstra<int>> dijkstra{ { a, 0 }, { a, 1 }, { a, 2 }, { a, 3 } };

	cout << dijkstra[0][0] << endl;
	cout << dijkstra[1][2] << endl;
	cout << dijkstra[2][1] << endl;
	cout << dijkstra[3][2] << endl;
}