#pragma once
#include <vector>
#include <algorithm>

using namespace std;
/* given an array A of N integers, returns the smallest positive 
integer (greater than 0) that does not occur in A.

For example, 
given A = [1, 3, 6, 4, 1, 2], the function should return 5.
*/

class SmallestPositiveInteger
{
public:
	int find(vector<int> &A);
};

