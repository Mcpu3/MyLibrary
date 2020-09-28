#include <algorithm>
#include <iostream>
#include <vector>
#include "binary_search.hpp"
using namespace std;

template<typename T>
bool is_ok_l(const vector<T>& a, const T& key, const int& mid) {
	return a[mid] >= key;
}

template <typename T>
bool is_ok_u(const vector<T>& a, const T& key, const int& mid) {
	return a[mid] > key;
}

int main() {
	int n;
	cin >> n;
	vector<int> S(n);
	for (int& i : S) cin >> i;
	sort(S.begin(), S.end());
	int q;
	cin >> q;
	vector<int> T(q);
	for (int& i : T) cin >> i;
	int ans = 0;
	for (const int& i : T) {
		ans += BinarySearch<int>::binary_search(S, i, is_ok_l)
			!= BinarySearch<int>::binary_search(S, i, is_ok_u);
	}
	cout << ans << endl;
}