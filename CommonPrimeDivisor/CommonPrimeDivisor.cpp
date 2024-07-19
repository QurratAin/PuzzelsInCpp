#include "CommonPrimeDivisor.h"

unsigned int CommonPrimeDivisor::gcd(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

unsigned long int CommonPrimeDivisor::hasCommon(unsigned long int num, unsigned long int factor) {
    while ((factor = gcd(num, factor)) != 1) {
        num /= factor;
    }
    return num;
}

int CommonPrimeDivisor::solution(vector<int>& A, vector<int>& B)
{
    int count = 0;

    for (int idx = 0; idx < static_cast<int>(A.size()); ++idx) {
        unsigned long int common_fac = gcd(B[idx], A[idx]);

        if (hasCommon(B[idx], common_fac) == 1) {
            if (hasCommon(A[idx], common_fac) == 1) {
                ++count;
            }
        }
    }
    return count;
}
