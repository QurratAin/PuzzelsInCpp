#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../runningAverage/runningAverage.h"

TEST(runningAvg, sample) {
	MovingAverage mover(3);
	ASSERT_EQ(1.0 , mover.next(1.0));
	ASSERT_EQ(1.5, mover.next(2.0));
	ASSERT_EQ(2.0, mover.next(3.0));
	ASSERT_EQ(2.0, mover.next(1.0));
}
