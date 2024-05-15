#include "EquivalentPair.h"
#include <algorithm>

int EquivalentPair::numEquivDominoPairs(vector<vector<int>>& dominoes)
{  
    for (auto& pair : dominoes) {
        if (pair[0] > pair[1])
            swap(pair[0], pair[1]); // We swap the numbers so that [1,2] and [2,1] can be counted together as [1,2]
        dominoe_checker[{pair[0], pair[1]}]++;
    }
    
    int ans = 0;

    for (auto & m : dominoe_checker)
        ans += m.second * (m.second - 1) / 2;  // Formula for sum of first n-1 numbers
    
    return ans;
}
