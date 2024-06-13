#include "SmallestPositiveInteger.h"

int SmallestPositiveInteger::find(vector<int>& A)
{
    int positive_number = 1;

    // sort and remove duplicate data
    std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());

    for (auto number : A) {
        if (number > 0) {
            if (number == positive_number) {
                ++positive_number;
            }
            else {
                return positive_number;
            }
        }
    }

    return positive_number;
}
