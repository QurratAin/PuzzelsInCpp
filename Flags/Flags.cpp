#include "Flags.h"

int Flags::solution(vector<int>& A)
{
    if (A.size() < 3)
        return 0;

    int a_size = static_cast<int>(A.size());
    vector<int> peaks;
    for (int index = 1; index < a_size - 1; ++index) {
        if (A[index] > A[index - 1] && A[index] > A[index + 1]) {
            peaks.push_back(index);
        }
    }

    int peaks_count = peaks.size();
    if (peaks_count > 0) {
        //maximum flags are dependent on the length of input.
        //e.g. if array size is 12
        // then 3(flags) X 3(distance) = 9(index)
        // are possible. 
        // 4(flags) X 4(distance) = 16(index) not possible 
        int maxflags = min(static_cast<int>(floor(sqrt(a_size))), peaks_count);
        int flags = 1, prev_peak = peaks[0];
        int maximum = 0;
        while (maxflags > 0) {
            for (int idx = 1; idx < peaks_count; ++idx) {
                if ((peaks[idx] - prev_peak) >= maxflags) {
                    ++flags;
                    prev_peak = peaks[idx];
                }
                if (flags >= maxflags) break;
            }
            maximum = max(maximum, flags);
            flags = 1;
            prev_peak = peaks[0];
            --maxflags;
        }
      
        return maximum;
    }
    else {
        return 0;
    }
}
