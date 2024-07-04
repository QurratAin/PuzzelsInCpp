#include "pch.h"
#include <gtest/gtest.h>
#include "../Brackets/Brackets.h"

TEST(testbrackets, correctclosing) {
	Brackets test_obj;
	string test_str{ "{{}}[()]" };
	ASSERT_EQ(1, test_obj.solution(test_str));
}

TEST(testbrackets, incorrectclosing) {
	Brackets test_obj;
	string test_str{ "{{[()]" };
	ASSERT_EQ(0, test_obj.solution(test_str));
}