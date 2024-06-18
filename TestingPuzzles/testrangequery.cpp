#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../GeonomicRangeQuery/RangeQuery.h"

using namespace std;

TEST(rangequery, sampletest) {

	RangeQuery test_obj;
	string test_str_one{ "CAGCCTA"};
	string test_str_two{ "CTGCCTCG" };
	vector<int> P_test{2, 5, 0, 0, 2, 3, 1};
	vector<int> Q_test{4, 5, 6, 3, 3, 5, 4};
	vector<int> result_one{2, 4, 1, 1, 2, 2, 1};
	vector<int> result_two{2, 4, 2, 2, 2, 2, 2};
	EXPECT_EQ(result_one, test_obj.solution_one(test_str_one, P_test, Q_test));
	EXPECT_EQ(result_two, test_obj.solution_one(test_str_two, P_test, Q_test));
	EXPECT_EQ(result_one, test_obj.solution_two(test_str_one, P_test, Q_test));
	EXPECT_EQ(result_two, test_obj.solution_two(test_str_two, P_test, Q_test));
	EXPECT_EQ(result_one, test_obj.solution_three(test_str_one, P_test, Q_test));
	EXPECT_EQ(result_two, test_obj.solution_three(test_str_two, P_test, Q_test));
}