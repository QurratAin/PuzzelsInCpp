#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MaxSliceSum/MaxSliceSum.h"

TEST(testslicesum, sampleone) {

	MaxSliceSum test_obj;
	vector<int> A{ 3, 2, -6, 4,0 };
	vector<int> B{ -10, -3, -2, -6, -21, -11, -1, -41};
	ASSERT_EQ(5, test_obj.solution(A));
	ASSERT_EQ(-1, test_obj.solution(B));
}