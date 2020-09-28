#include <iostream>
#include <vector>
#include "gcm_lcm.hpp"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int ans = a.front();
	for (int i = 1; i < n; i++) ans = GCMLCM<int>::lcm(ans, a[i]);
	cout << ans << endl;
}