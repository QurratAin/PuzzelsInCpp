#include "OddOccurance.h"

int OddOccurance::find(vector<int>& A)
{
    sort(A.begin(), A.end());
    int length_a = A.size(), pos = 0;
    while (pos < length_a) {
        if (A[pos] != A[pos + 1]) {
            return A[pos];
        }
        pos += 2;
    }
    return A.back();
}
