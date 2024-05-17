#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../RomanToInteger/RomanToInteger.h"

TEST(RomanToIntegerI, sampleI) {
	RomanToIntegerI num;
	ASSERT_EQ(1994,num.romanToInt("MCMXCIV"));
	ASSERT_EQ(58, num.romanToInt("LVIII"));
}

TEST(RomanToIntegerII, smapleII) {
	RomanToIntegerII num;
	ASSERT_EQ(1994, num.romanToInt("MCMXCIV"));
	ASSERT_EQ(58, num.romanToInt("LVIII"));
}