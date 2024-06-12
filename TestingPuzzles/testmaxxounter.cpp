#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../MaxCounter/MaxCounter.h"

TEST(maxcounter, testsample) {
	MaxCounter counter;
	vector<int> test_vec{3,4,4,6,1,4,4};
	vector<int> result{3, 2, 2, 4, 2};
	vector<int> calculated_one = counter.solution_one((int)result.size(), test_vec);
	vector<int> calculated_two = counter.solution_two((int)result.size(), test_vec);
	EXPECT_EQ(calculated_one, result);
	EXPECT_EQ(calculated_two, result);
}