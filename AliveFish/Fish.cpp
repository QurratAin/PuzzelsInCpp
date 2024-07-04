#include "Fish.h"


int Fish::solution(vector<int>& A, vector<int>& B)
{
    stack<pair<int, int>> river;

    for (int index = 0; index < static_cast<int>(A.size()); ++index) {
        if (!river.empty()) {
            if (B[index] == 0 && river.top().second == 1) {
                // when fish meet and fight
                while ((!river.empty()) &&
                    river.top().first < A[index] &&
                    river.top().second != B[index]) {
                    // fish get eaten if current one is larger  
                    // than the top of stack
                    river.pop();         
                }
                if (river.empty()) {
                    // if stack gets empty after popping
                    river.push({ A[index], B[index] });
                }else if (river.top().second == 0) {
                    // if the current one eats, then it need
                    // to be on the stack. if the top of stack
                    // fish eats, nothing to be done.
                    river.push({ A[index], B[index] });
                }
            }
            else {
                //when fish don't meet
                river.push({ A[index], B[index] });
            }
        }
        else {
            // river is empty
            river.push({ A[index], B[index] });
        }       
    }

    return static_cast<int>(river.size());
}
