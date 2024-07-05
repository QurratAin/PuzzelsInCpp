#include "Dominator.h"

int Dominator::solution(vector<int>& A)
{
    long int top_val;
    int stack_size = 0;
    for (auto num : A) {
        if (stack_size == 0) {
            ++stack_size;
            top_val = num;
        }
        else if (top_val != num) {
            --stack_size;
        }
        else {
            ++stack_size;
        }
    }

    if (stack_size > 0) {
        if (std::count(A.begin(), A.end(), top_val) > static_cast<int>(A.size() / 2)) {
            return std::find(A.begin(), A.end(), top_val) - A.begin();
        }
        else {
            return -1;
        }    
    }
    else {
        return -1;
    }

}
