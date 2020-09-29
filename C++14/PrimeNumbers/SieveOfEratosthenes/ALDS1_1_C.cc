#include <algorithm>
#include <iostream>
#include <vector>
#include "sieve_of_eratosthenes.hpp"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int ans = 0;
	SieveOfEratosthenes sieve_of_eratosthenes(*max(a.begin(), a.end()));
	for (const int& i : a) ans += sieve_of_eratosthenes[i];
	cout << ans << endl;
}