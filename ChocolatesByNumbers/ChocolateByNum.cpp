#include "ChocolateByNum.h"

int ChocolateByNum::solution(int N, int M)
{
    int count = 0;
    unsigned long int new_num = N;
    if (N < M) {
        auto div_small = std::ldiv(M, N);
        if (div_small.rem == 0) {
            new_num = (N * div_small.quot);
        }
        else {
            new_num = (N * div_small.quot) + N;
        }
    }

    auto div = std::ldiv(new_num, M);
    count += div.quot;

    while (div.rem != 0) {
        new_num = N + div.rem;
        div = std::ldiv(new_num, M);
        count += div.quot;
    }

    return count;
}
