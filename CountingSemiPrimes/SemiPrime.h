#pragma once
#include <vector>
#include <algorithm>
using namespace std;
/*A prime is a positive integer X that has exactly two 
distinct divisors: 1 and X. The first few prime 
integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product
of two (not necessarily distinct) prime numbers. 
The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty arrays P and Q, each
consisting of M integers. These arrays represent 
queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes 
within the range (P[K], Q[K]), where 1 ? P[K] ? Q[K] ? N.

For example, consider an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.
*/

class SemiPrime
{
public:

	vector<int> solution(int N, vector<int>& P, vector<int>& Q);
};

