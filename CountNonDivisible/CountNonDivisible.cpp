#include "CountNonDivisible.h"

vector<int> CountNonDivisible::solution_two(vector<int>& A)
{
    vector<int> count(A.size(), 0);
    int a_size = static_cast<int>(A.size());
    for (int x_index = 0; x_index < a_size; ++x_index) {
        for (int y_index = x_index + 1; y_index < a_size; ++y_index) {
            int diff = A[x_index] - A[y_index];
            if (diff > 0) {
                if (A[x_index] % A[y_index] != 0) {
                    ++count[x_index];
                }
                ++count[y_index];
            }
            else if (diff < 0) {
                if (A[y_index] % A[x_index] != 0) {
                    ++count[y_index];
                }
                ++count[x_index];
            }

        }
    }

    return count;
}
vector<int> CountNonDivisible::solution(vector<int>& A)
{
    // the maximum number can be 2N+1
    int n = static_cast<int>(A.size());
    int max_length = (n * 2) + 1;
    vector<int> count(max_length, 0);
    vector<int> divisible(max_length, 0);
    vector<int> result(n, 0);
    
    // initialize with count of duplicates
    // coz they will be divisible with themselves
    for (auto idx : A) ++count[idx];

    for (int num = 1; num < max_length; ++num) {
        /* go over the numbers to count the factors(divisbles)
         A = [3, 1, 2, 3, 6] 
                    1 2 3 4 5 6 7 8 9 10
        count =     1 1 2 0 0 1 0 0 0 0 
        divisible = 1 2 3 2 1 5 1 2 3 2
        */
       
        for (unsigned long long int factor = num * num; factor < max_length; factor += num) {
            divisible[factor] += count[num];
            if (factor != num * num) {
                divisible[factor] += count[factor / num];
            }

        }
        
    }

    for (int i = 0; i < static_cast<int>(A.size()); ++i) {
        result[i] = n - divisible[A[i]];
    }

    return result;
}

vector<int> CountNonDivisible::solution_one(vector<int>& A)
{
    
    vector<int> result(A.size(), 0);
    int idx = 0;
    for (auto num : A) {
        int non_div = std::count_if(A.begin(), A.end(), [&num](int x) { return ( num % x) != 0; });
        result[idx] = non_div;
        ++idx;
    }

    return result;
}
