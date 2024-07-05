#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../Dominator/Dominator.h"

TEST(testdominator, exacthalfeven) {
	Dominator test_obj;
	vector<int> A{ 0, 0, 0, 1, 0, 2, 2, 2, 2, 2 };
	vector<int> B{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
				   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	vector<int> C{ 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 };
	ASSERT_EQ(-1, test_obj.solution(A));
	ASSERT_EQ(10, test_obj.solution(B));
	ASSERT_EQ(-1, test_obj.solution(C));
}

TEST(testdominator, nodominator) {
	Dominator test_obj;
	vector<int> A{ 0, 2, 5, 3, 1 };
	ASSERT_EQ(-1, test_obj.solution(A));
}

TEST(testdominator, halfplusone) {
	Dominator test_obj;
	vector<int> A{ 0, 2, 2, 0, 1, 0, 2, 2, 2, 2 };
	ASSERT_EQ(1, test_obj.solution(A));
}
