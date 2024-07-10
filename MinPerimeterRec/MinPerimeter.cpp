#include "MinPerimeter.h"

int MinPerimeter::solution(int N)
{
    for (int num = sqrt(N); num > 1; --num) {
        auto complete_div = std::div(N, num);
        if (complete_div.rem == 0) {
            // perfect minimum factors
            return (num + complete_div.quot) * 2;
        }
    }

    // N is prime
    return (N + 1) * 2;
}
