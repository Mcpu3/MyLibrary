#include <iostream>
#include "binary_search.cc"
using namespace std;

int main() {
	vector<int> a{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	cout << BinarySearch::binary_search(a, 0) << endl;
	cout << BinarySearch::binary_search(a, 11) << endl;
	cout << BinarySearch::binary_search(a, 12) << endl;
	cout << BinarySearch::binary_search(a, 30) << endl;
}