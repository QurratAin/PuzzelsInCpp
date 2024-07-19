#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../CommonPrimeDivisor/CommonPrimeDivisor.h"

TEST(commonprimedivisor, example1) {
	CommonPrimeDivisor test_obj;
	vector<int> A{15, 10, 3};
	vector<int> B{75, 30, 5};
	ASSERT_EQ(1, test_obj.solution(A, B));

}