#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../CountingSemiPrimes/SemiPrime.h"


TEST(countsemiprime, sample1) {
	SemiPrime test_obj;
	vector<int> P{1, 4, 16};
	vector<int> Q{26, 10, 20};
	int N = 26;
	vector<int> result{10, 4, 0};
	ASSERT_EQ(result, test_obj.solution(N, P, Q));

}