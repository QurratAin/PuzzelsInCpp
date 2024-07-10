#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MaxDoubleSlice/MaxDoubleSlice.h"

TEST(testmaxdoubleslice, sampleone) {
	MaxDoubleSlice test_obj;
	vector<int> A{3, 2, 6, -1, 4, 5, -1, 2}; 
	ASSERT_EQ(17, test_obj.solution(A));
}

TEST(testmaxdoubleslice, sampletwo) {
	MaxDoubleSlice test_obj;
	vector<int> A{-8, 10, 20, -5, -7, -4};
	ASSERT_EQ(30, test_obj.solution(A));
}