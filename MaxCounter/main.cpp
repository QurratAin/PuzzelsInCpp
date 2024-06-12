#include <iostream>
#include <vector>
#include <chrono>
#include "MaxCounter.h"

unsigned long long time_it(int X, vector<int>& A, vector<int> (*func)(int, vector<int>&)) {

	auto start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto ans = func(X, A);
	auto end = std::chrono::high_resolution_clock::now().time_since_epoch().count();

	return end - start;
}

int main(int argc, char* argv[]) {

	vector<int> test;
	for (int i = 0; i < 1000; i++)
		test.push_back((std::rand() % 50) + 1);

	auto soultion_one_time = time_it( 40, test, &MaxCounter::solution_one);
	auto soultion_two_time = time_it(40, test, &MaxCounter::solution_two);

	cout << "solution one " << soultion_one_time << endl
		<< "solution_ two " << soultion_two_time << endl;
	return 0;
}