#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../EqualizeFrequency/equalFrequency.h"

using namespace std;

TEST(equalize_freq, example1) {
	string test_word = "bbac";
	equalFrequency test;
	ASSERT_EQ(true, test.calculate(test_word));
}

TEST(equalize_freq, example2) {
	string test_word = "ddaccb";
	equalFrequency test;
	ASSERT_EQ(false, test.calculate(test_word));
}

TEST(equalize_freq, example3) {
	string test_word = "bac";
	equalFrequency test;
	ASSERT_EQ(true, test.calculate(test_word));
}

TEST(equalize_freq, example4) {
	string test_word = "aazz";
	equalFrequency test;
	ASSERT_EQ(false, test.calculate(test_word));
}