#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include "RangeQuery.h"
#include <random>

unsigned long long time_it(string &s, vector<int> &X, vector<int>& A, vector<int> (*func)(string &, vector<int>&, vector<int> &)) {

	auto start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto ans = func(s, X, A);
	auto end = std::chrono::high_resolution_clock::now().time_since_epoch().count();

	return end - start;
}

int main(int argc, char* argv[]) {

	vector<int> test_P, test_Q;
	for (int i = 0; i < 5000; i++) {
		int start = std::rand() % 30;
		int end = std::rand() % 80;
		test_P.push_back(start);
		test_Q.push_back(start + end);
	}

	vector<char> G(4000, 'G');
	vector<char> A(1000, 'A');
	vector<char> C(5000, 'C');
	vector<char> T(3000, 'T');

	vector<char> test_v;
	test_v.insert(test_v.end(), A.begin(), A.end());
	test_v.insert(test_v.end(), C.begin(), C.end());
	test_v.insert(test_v.end(), G.begin(), G.end());
	test_v.insert(test_v.end(), T.begin(), T.end());
	// Create a random number generator
	random_device rd;
	mt19937 generator(rd());
	std::shuffle(test_v.begin(), test_v.end(), generator);

	string test_S(test_v.begin(), test_v.end());

	auto solution_one = time_it(test_S, test_P, test_Q, &RangeQuery::solution_one);
	auto solution_two = time_it(test_S, test_P, test_Q, &RangeQuery::solution_two);
	auto solution_three = time_it(test_S, test_P, test_Q, &RangeQuery::solution_three);
	
	cout << "Solution one: " << solution_one << endl
		<< "Solution two: " << solution_two << endl
		<< "Solution three: "<< solution_three << endl;
	return 0;

}