#pragma once

template <typename T>
class TrialDivision {
public:
	static bool is_prime(const T& a) {
		if (a <= 1) return false;
		bool _is_prime = true;
		for (T i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				_is_prime = false;
				break;
			}
		}
		return _is_prime;
	}
};