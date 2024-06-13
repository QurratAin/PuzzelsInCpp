#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../SmallestPositiveInteger/SmallestPositiveInteger.h"

TEST( testsmallestpositiveinteger, sampleone) {

	SmallestPositiveInteger test_obj;

	vector<int> test_vec_one{ 1, 3, 2, 1, 4, 6};
	vector<int> test_vec_two{ -4, -3, -1, 0, -6, -6 };
	vector<int> test_vec_three{ -10000, 10000 };
	vector<int> test_vec_four{ 10, 20, 30, 20, 40, 35, 8 };

	ASSERT_EQ(5, test_obj.find(test_vec_one));
	ASSERT_EQ(1, test_obj.find(test_vec_two));
	ASSERT_EQ(1, test_obj.find(test_vec_three));
	ASSERT_EQ(1, test_obj.find(test_vec_four));
}