#include <iostream>
#include "trial_division.hpp"
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans += TrialDivision<int>::is_prime(a);
	}
	cout << ans << endl;
}