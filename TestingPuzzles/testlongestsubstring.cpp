#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../LongestString/LongestSubstring.h"

TEST(Longest_substring, example) {

	LongestSubstring test_example;
	ASSERT_EQ(3, test_example.SlidingWindowLength("pwwkew"));
	ASSERT_EQ(3, test_example.SlidingWindowLength("dvdf"));
	ASSERT_EQ(3, test_example.SlidingWindowLength("abcabcbb"));
	ASSERT_EQ(1, test_example.SlidingWindowLength(" "));
	ASSERT_EQ(3, test_example.lengthOfLongestSubstring("dvdf"));
	ASSERT_EQ(3, test_example.lengthOfLongestSubstring("abcabcbb"));
	ASSERT_EQ(1, test_example.lengthOfLongestSubstring("bbb"));
	
}
