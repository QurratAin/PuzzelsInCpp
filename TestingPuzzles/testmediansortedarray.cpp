#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include "../MedianSortedArray/Median.h"

using namespace std;

TEST(TestMedian, EvenNumberOfElement) {

	vector<double> num1{-3, -2, 0, 5, 8, 9, 22};
	vector<double> num2{-15, -9, -1, 3, 12, 16, 42, 55, 66};
	Median test_median(num1, num2);
	test_median.calculate_median();

	ASSERT_EQ(test_median.median, 6.5);

}

TEST(TestMedian, OddNumberOfElements) {

	vector<double> num1{ -1, 0, 4, 6, 9, 10};
	vector<double> num2{ -3, -1, 3, 7, 11 };
	Median test_median(num1, num2);
	test_median.calculate_median();

	ASSERT_EQ(test_median.median, 4.0);

}