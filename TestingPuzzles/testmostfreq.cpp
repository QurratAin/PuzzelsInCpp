#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MostFreq/frequency.h"

using namespace std;

TEST(most_freq, example1) {
	vector<int> test_vector{ 1, 3, 1, 3, 2, 1 };
	frequency test_map;
	test_map.create_map(test_vector);
	int freq = -1, ele = -1;
	test_map.max_duplicate_key(freq, ele);
	ASSERT_EQ(3, freq);
	ASSERT_EQ(1, ele);

}

TEST(most_freq, example2) {
	vector<int> test_vector{ 6, 30, 11, 13, 12, 11, 30, 6, 10, 8, 4, 2, 12, 11, 120, 11 };
	frequency test_map;
	test_map.create_map(test_vector);
	int freq = -1, ele = -1;
	test_map.max_duplicate_key(freq, ele);
	ASSERT_EQ(4, freq);
	ASSERT_EQ(11, ele);
}
