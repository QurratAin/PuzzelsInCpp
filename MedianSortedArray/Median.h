#pragma once
#include <algorithm>
#include <vector>

using namespace std;

class Median {
private:
	vector<double> first;
	vector<double> second;

public:
	double median;
	Median() : median(0.0) {};
	Median(vector<double> input_first, vector<double> input_second)
		: first(input_first), second(input_second), median(0.0) {};
	void calculate_median();


};