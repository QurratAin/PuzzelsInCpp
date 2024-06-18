#pragma once
#include <string>
#include <string_view>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*given a non-empty string S consisting of N characters 
and two non-empty arrays P and Q consisting of M integers, 
returns an array consisting of M integers specifying the 
consecutive answers to all queries.

Result array should be returned as an array of integers.

For example, given the string S = CAGCCTA and 
arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], 
as explained above.
*/

class RangeQuery
{
public:
    vector<int> static solution_one(string& S, vector<int>& P, vector<int>& Q);
    vector<int> static solution_two(string& S, vector<int>& P, vector<int>& Q);
    vector<int> static solution_three(string& S, vector<int>& P, vector<int>& Q);
};

