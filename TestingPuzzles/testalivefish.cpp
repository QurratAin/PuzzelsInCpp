#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../AliveFish/Fish.h"

TEST(testalivefish, fishgoup) {
	Fish test_obj;
	vector<int> A{4, 3, 2 ,1, 5};
	vector<int> B{0, 1, 0, 0, 0};
	ASSERT_EQ(2, test_obj.solution(A, B));
}

TEST(testalivefish, fishgodwon) {
	Fish test_obj;
	vector<int> A{ 4, 2, 3 ,7, 5, 6 };
	vector<int> B{ 1, 1, 1, 1, 1, 0 };
	ASSERT_EQ(4, test_obj.solution(A, B));
}

TEST(testalivefish, onefisheatall) {
	Fish test_obj;
	vector<int> A{ 4, 2, 3 ,1, 5, 6 };
	vector<int> B{ 1, 1, 1, 1, 1, 0 };
	ASSERT_EQ(1, test_obj.solution(A, B));
}