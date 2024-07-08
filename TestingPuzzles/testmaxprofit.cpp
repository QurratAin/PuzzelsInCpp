#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MaxProfit/MaxProfit.h"

TEST(testmaxprofit, sampleone) {

	MaxProfit test_obj;
	vector<int> A{23171, 21011, 21123, 21366, 21013, 21367};
	ASSERT_EQ(356, test_obj.solution(A));
}