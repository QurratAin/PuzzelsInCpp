#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../CountNonDivisible/CountNonDivisible.h"


TEST(countnondivisible, sample1) {
	CountNonDivisible test_obj;
	vector<int> A{ 3, 1, 2, 3, 6 };
	vector<int> A_result{ 2, 4, 3, 2, 0 };
	ASSERT_EQ(A_result, test_obj.solution_one(A));
	ASSERT_EQ(A_result, test_obj.solution(A));

	int N = 100;
	vector<int> large_test(N, 0);
	for (int i = 0; i < N; ++i) {
		large_test[i] = (std::rand() % N) + 1;
	}

	ASSERT_EQ(test_obj.solution_one(large_test), test_obj.solution(large_test));
}