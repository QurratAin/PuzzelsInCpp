#pragma once
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
using namespace std;
class CountNonDivisible
{
public:
	// solution_one perform better than solution_two
	vector<int> solution_one(vector<int>& A);
	// hoping for nlogn performance, but still not fast enough
	vector<int> solution_two(vector<int>& A);
	vector<int> solution(vector<int>& A);
};

