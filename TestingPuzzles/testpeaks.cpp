#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../Peaks/Peaks.h"

TEST(testpeaks, threepeaks) {
	Peaks test_obj;
	vector<int> A{ 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };
	ASSERT_EQ(3, test_obj.solution(A));
}

TEST(testpeaks, onepeak) {
	Peaks test_obj;
	vector<int> A{ 1, 3, 1, 1 };
	ASSERT_EQ(1, test_obj.solution(A));
}

TEST(testpeaks, twopeaks) {
	Peaks test_obj;
	vector<int> A{ 1, 3, 1, 3, 1 };
	ASSERT_EQ(1, test_obj.solution(A));
	vector<int> B{ 1, 3, 1, 3, 2, 1 };
	ASSERT_EQ(2, test_obj.solution(B));
	vector<int> C{1, 3, 1, 1, 3, 1, 1, 1, 1};
	ASSERT_EQ(1, test_obj.solution(C));
}