#include "pch.h"
#include <gtest/gtest.h>
#include "../ChocolatesByNumbers/ChocolateByNum.h"

TEST(testchocolatebynum, nislessthanm) {

	ChocolateByNum test_obj;
	ASSERT_EQ(7, test_obj.solution(7, 20));
}

TEST(testchocolatebynum, nisgreaterthanm) {

	ChocolateByNum test_obj;
	ASSERT_EQ(5, test_obj.solution(10, 4));
}

TEST(testchocolatebynum, nisequaltom) {

	ChocolateByNum test_obj;
	ASSERT_EQ(1, test_obj.solution(7, 7));
}