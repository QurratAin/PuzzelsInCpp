#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../EquiLeader/EquiLeader.h"

TEST(testequileader,  sampleone) {
	EquiLeader test_obj;
	vector<int> A{4, 3, 4, 4, 4, 2};
	ASSERT_EQ(2, test_obj.solution_slow(A));
	ASSERT_EQ(2, test_obj.solution(A));
}