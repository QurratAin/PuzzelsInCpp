#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MinPerimeterRec/MinPerimeter.h"

TEST(testminperimeter, sampleone) {
	MinPerimeter test_obj;
	ASSERT_EQ(22, test_obj.solution(30));
	ASSERT_EQ(1238, test_obj.solution(1234));
	ASSERT_EQ(20, test_obj.solution(24));
	ASSERT_EQ(8552, test_obj.solution(4564320));
}