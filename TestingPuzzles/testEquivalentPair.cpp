#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../EquivalentPair/EquivalentPair.h"

TEST(equPair, sample) {
	EquivalentPair eq;
	vector<vector<int>> dominoes{ {1, 2} ,{1, 2},{1, 1},{1, 2}, {2, 2} ,{2,1} };
	ASSERT_EQ(6, eq.numEquivDominoPairs(dominoes));
	
}