#include "pch.h"
#include <vector>
#include <gtest/gtest.h>
#include "../Flags/Flags.h"

TEST(testflags, smapleone) {

	Flags test_obj;
	vector<int>  A{1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
	ASSERT_EQ(3, test_obj.solution(A));
}

TEST(testflags, maxpeaks) {

	Flags test_obj;
	vector<int>  A{ 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4};
	ASSERT_EQ(3, test_obj.solution(A));
}