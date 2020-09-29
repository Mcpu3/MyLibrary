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
		for (int _i = 2; _i * _i <= n; _i++) {
			if (!_is_prime[_i]) continue;
			for (int _j = _i * _i; _j <= n; _j += _i) _is_prime[_j] = false;
		}
	}

public:
	bool operator[](const int& index) const {
		return _is_prime[index];
	}
};