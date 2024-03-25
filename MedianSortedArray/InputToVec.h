#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class InputToVec {
public:
	vector<double> double_vector;
	void get_double_numbers_from_user();
	bool check_vector_sorted();
};