#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MinDiffPart/MinDiffPart.h"

using namespace std;

TEST(TestMinDiffPart, sample) {
	MinDiffPart test_obj;
	vector<int> test_vec1{3, 1, 2, 4, 3};
	vector<int> test_vec2{1, 1, 3};
	ASSERT_EQ(1, test_obj.find_partition_point(test_vec1));
	ASSERT_EQ(1, test_obj.find_partition_point(test_vec2));
	
}