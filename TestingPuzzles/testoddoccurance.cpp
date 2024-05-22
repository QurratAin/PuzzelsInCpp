#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../OddOccurance/OddOccurance.h"

using namespace std;

TEST(testOddOccurance, sample1) {
	OddOccurance test_obj;
	vector<int> test_vec1{1,2,3,5,1,3,5};
	ASSERT_EQ(2, test_obj.find(test_vec1));
	vector<int> test_vec2{2};
	ASSERT_EQ(2, test_obj.find(test_vec2));

}
