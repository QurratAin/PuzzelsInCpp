// MedianSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "util.h"
#include "Median.h"

using namespace std;

/// <summary>
/// Given two sorted arrays nums1 and nums2 of size m and n respectively, 
/// return the median of the two sorted arrays.The overall run time
/// complexity should be O(log(m + n)).
/// </summary>
/// <returns></returns>
int main()
{
	//get input from user
	vector<double> first_array, second_array;
	ConsoleInput::string_to_vec<double>("Please Enter first array of space sepearted double numbers.", first_array);
	if (!is_sorted(first_array.begin(), first_array.end())) {
		cout << "First array is not sorted" << endl;
		return 0;
	}
	ConsoleInput::string_to_vec<double>("Please Enter second array of space sepearted double numbers.", second_array);
	if (!is_sorted(second_array.begin(), second_array.end())) {
		cout << "Second array is not sorted" << endl;
		return 0;
	}
	//calculate median
	Median med(first_array, second_array);
	med.calculate_median();
	cout << "The median is " << med.median << endl;

	return med.median;
}