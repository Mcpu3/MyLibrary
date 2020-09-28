#pragma once

template <typename T>
class GCMLCM {
public:
	static T gcm(const T& a, const T& b) {
		return b ? gcm(b, a % b) : a;
	}

public:
	static T lcm(const T& a, const T& b) {
		return a / gcm(a, b) * b;
	}
};