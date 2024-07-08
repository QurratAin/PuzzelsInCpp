#include "MaxProfit.h"

int MaxProfit::solution(vector<int>& A)
{
    long long int max_profit = 0, max_diff = 0;
    if (A.size() > 1) {
        for (int index = 1; index < static_cast<int>(A.size()); ++index) {
            max_diff = max(0ll, max_diff + (static_cast<long long int>(A[index]) - static_cast<long long int>(A[index - 1])));
            max_profit = max(max_profit, max_diff);
        }
    }

    return max_profit;
}
