#include "pch.h"
#include <iostream>

#include "InputToVec.h"
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
	InputToVec first_array, second_array;
	first_array.get_double_numbers_from_user();
	if (!first_array.check_vector_sorted()) {
		cout << "The array is not sorted" << endl;
		return 0;
	}
	second_array.get_double_numbers_from_user();
	if (!second_array.check_vector_sorted()) {
		cout << "The array is not sorted" << endl;
		return 0;
	}
	//calculate median
	Median med(first_array.double_vector, second_array.double_vector);
	med.calculate_median();
	cout << "The median is " << med.median << endl;

	return med.median;
}
