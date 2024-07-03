#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MinAvgTwoSlice/MinAvg.h"

using namespace std;

TEST(testminavg, sampleone) {
	// (1, 4) produces the minimum avg,
	// reuslt should be 1.
	vector<int> test_vec{ 4, 2, 2, 5, 1, 5, 8 };
	ASSERT_EQ(1, MinAvg::solution(test_vec));
	ASSERT_EQ(1, MinAvg::solution_slow(test_vec));
}

TEST(testminavg, smapletwo) {
	vector<int> test_vec{ -3, -5, -8, -4, -10 };
	ASSERT_EQ(2, MinAvg::solution_slow(test_vec));
	ASSERT_EQ(2, MinAvg::solution(test_vec));
}

TEST(testminavg, smaplethree) {
	vector<int> test_vec{ 10, 10, -1, 2, 4, -1, 2, -1 };
	ASSERT_EQ(5, MinAvg::solution_slow(test_vec));
	ASSERT_EQ(5, MinAvg::solution(test_vec));
}
