#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <chrono>
#include "../CountingBits/CountingBits.h"


TEST(countingbits, sample1) {
	CountingBits test_obj;
	vector<int> test;
	for (int i = 0; i < 1000; i++)
		test.push_back(std::rand() % 500);

	int ans_bit_1 = test_obj.counting_bits_boolvec(60, test);
	int ans_bit_2 = test_obj.counting_bits_bitflip(60, test);
	int ans_bit_3 = test_obj.counting_bits_hash(60, test);
	int ans_bit_4 = test_obj.counting_bits_set(60, test);
	int ans_bit_5 = test_obj.counting_bits_boolarray(60, test);

	ASSERT_EQ(ans_bit_1, ans_bit_2);
	ASSERT_EQ(ans_bit_1, ans_bit_3);
	ASSERT_EQ(ans_bit_1, ans_bit_4);
	ASSERT_EQ(ans_bit_1, ans_bit_5);

}