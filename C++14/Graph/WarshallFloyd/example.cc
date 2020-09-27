#include <iostream>
#include "warshall_floyd.cc"
using namespace std;

int main() {
	vector<vector<pair<int, int>>> a{
		{ { 1, 2 }, { 2, 3 } },
		{ { 0, 5 }, { 3, 7 } },
		{ { 0, 11 } },
		{ { 1, 13 } }
	};
	WarshallFloyd<int> warshall_floyd(a);

	cout << warshall_floyd(0, 0) << endl;
	cout << warshall_floyd(1, 2) << endl;
	cout << warshall_floyd(2, 1) << endl;
	cout << warshall_floyd(3, 2) << endl;
	cout << warshall_floyd.has_negative_cycle() << endl;
}