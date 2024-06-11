#include <iostream>
#include <vector>
#include <chrono>
#include "CountingBits.h"

unsigned long long time_it(int X, vector<int> &A, int (*func)(int, vector<int> &)) {

	auto start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	int ans = func(X, A);
	auto end = std::chrono::high_resolution_clock::now().time_since_epoch().count();

	return end - start;
}

int main(int argc, char* argv[]) {

	vector<int> test;
	for (int i = 0; i < 1000; i++)
		test.push_back(std::rand() % 50);

	auto boolvec = time_it(40, test, &CountingBits::counting_bits_boolvec);
	auto bitflip = time_it(40, test, &CountingBits::counting_bits_bitflip);
	auto hash = time_it(40, test, &CountingBits::counting_bits_hash);
	auto set = time_it(40, test, &CountingBits::counting_bits_set);
	auto boolarray = time_it(40, test, &CountingBits::counting_bits_boolarray);

	cout << "bitflip " << bitflip << endl <<
		"boolvec " << boolvec << endl <<	
		"set " << set << endl <<
		"hash " << hash << endl <<
		"boolarray " << boolarray << endl;
	return 0;
}