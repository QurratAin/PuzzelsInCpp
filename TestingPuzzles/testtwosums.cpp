#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../TwoSums/FindSum.h"

using namespace std;

TEST(TestTwoSums, FoundTarget) {
	vector<int> numbers{3, 2, 4, 5, 1};
	int target_sum = 5;
	FindSum test_sum;
	vector<int> target_result{ 0, 1 };
	vector<int> result = test_sum.check(numbers, target_sum);
	ASSERT_EQ(2, result.size());
	EXPECT_EQ(result, target_result);

	vector<int> result_hash = test_sum.check_by_hash(numbers, target_sum);
	EXPECT_EQ(result_hash, target_result);
}

TEST(TestTwoSums, NotFoundTarget) {
	vector<int> numbers{ 3, 2, 4, 5, 1 };
	int target_sum = 15;
	FindSum test_sum;
	vector<int> target_result{};
	vector<int> result = test_sum.check(numbers, target_sum);
	ASSERT_EQ(0, result.size());
	EXPECT_EQ(result, target_result);

	vector<int> result_hash = test_sum.check_by_hash(numbers, target_sum);
	EXPECT_EQ(result_hash, target_result);
}