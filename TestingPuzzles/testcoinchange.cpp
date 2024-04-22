#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../CoinChange/CoinChange.h"

TEST(coinchange, example1) {
	vector<int> coins1{4, 2, 5};
	vector<int> coins2{2};
	vector<int> coins3{ 1 };
	vector<int> coins4{ 186,419,83,408 };
	CoinChange changer;
	ASSERT_EQ(2, changer.find(coins1, 10));
	ASSERT_EQ(-1, changer.find(coins2, 3));
	ASSERT_EQ(0, changer.find(coins3, 0));
	ASSERT_EQ(20, changer.find(coins4, 6249));
}

