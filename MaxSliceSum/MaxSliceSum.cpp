#include "MaxSliceSum.h"

int MaxSliceSum::solution(vector<int>& A)
{
    long long int max_slice = 0, max_sum = 0;

    for (int index = 0; index < static_cast<int>(A.size()); ++index) {
        max_sum = max(0ll, max_sum + static_cast<long long int>(A[index]));
        max_slice = max(max_slice, max_sum);
    }
    // handles the case if all the numbers are negative
    if (max_slice == 0) {
        return *std::max_element(A.begin(), A.end());
    }
    else {
        return max_slice;
    }
}
