#include "Peaks.h"

void Peaks::get_factors(int N, vector<int>& factors) {
    double n_sqrt = sqrt(N);
    // if N is perfect sqrt
    if (ceil(n_sqrt) == floor(n_sqrt)) {
        factors.push_back(static_cast<int>(n_sqrt));
    }
    for (int num = 2; num < ceil(n_sqrt); ++num) {
        auto div = std::div(N, num);
        if (div.rem == 0) {
            factors.push_back(num);
            factors.push_back(div.quot);
        }
    }

    if (!factors.empty()) sort(factors.begin(), factors.end());
}


int Peaks::solution(vector<int>& A)
{
    int a_size = static_cast<int>(A.size());
    // no peak possible
    if (a_size < 3) { return 0; }

    //find peaks
    vector<int> peaks, a_factors;
    for (int idx = 1; idx < a_size; ++idx) {
        if (A[idx] > A[idx - 1] && A[idx] > A[idx + 1]) {
            peaks.push_back(idx);
        }
    }
    if (peaks.empty()) return 0;
    int numofpeaks = static_cast<int>(peaks.size());
    if (numofpeaks == 1) return 1;

    get_factors(a_size, a_factors);
    // if array is of prime number size,
    // there will be no factor, not divisible
    if(a_factors.empty()) return 1;  

    // the size of smallest block possible, which
    // will produces maximum number of blocks.

    int max_blocks = 1;
    for(auto blk_size : a_factors ) {
        int good_blocks = 0;
        for (auto peak : peaks) {
            if (static_cast<int>(floor(peak / blk_size)) == good_blocks) {         
                ++good_blocks;
            }
        }
        if (good_blocks == static_cast<int>(a_size / blk_size)) {
            max_blocks = good_blocks;
            break;
        }
    }

    return max_blocks;
}
