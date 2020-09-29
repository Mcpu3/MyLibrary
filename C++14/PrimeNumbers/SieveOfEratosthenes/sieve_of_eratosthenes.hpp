#pragma once

#include <vector>
using namespace std;

class SieveOfEratosthenes {
protected:
	vector<bool> _is_prime;

public:
	SieveOfEratosthenes(const int& n) : _is_prime(n + 1, true) {
		_is_prime[0] = false;
		_is_prime[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (!_is_prime[i]) continue;
			for (int j = i * i; j <= n; j += i) _is_prime[j] = false;
		}
	}

public:
	bool operator[](const int& index) const {
		return _is_prime[index];
	}
};