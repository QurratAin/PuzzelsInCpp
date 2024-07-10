#include "MaxDoubleSlice.h"

int MaxDoubleSlice::solution(vector<int>& A)
{
    vector<int> right_sum(A.size() - 2, 0);
    vector<int> left_sum(A.size() - 2, 0);

    int reduced_size = static_cast<int>(right_sum.size());
    int i = 1, j = reduced_size - 1;
    while (j > 0) {
        left_sum[i] = max(0, left_sum[i - 1] + A[i]);
        right_sum[j - 1] = max(0, right_sum[j] + A[j + 1]);
        ++i;
        --j;
    }

    int maxsum = 0;
    for (int index = 0; index < reduced_size; ++index) {
        maxsum = max(maxsum, left_sum[index] + right_sum[index]);
    }

    return maxsum;
}
