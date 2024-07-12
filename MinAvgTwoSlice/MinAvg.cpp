#include "MinAvg.h"
/* This solution approaches the problem with dynamic size window
* with the fact that adding number less than current average will
* decrease the overall average while adding a number greater than
* current window average will increase the average.
* The window increases at the end if the next number is less than
* current avreage of the window, which will decrease the average.
* The window shrinks from start when the window becomes the size of 
* array A or next number to be added in the windows is greater then
* current average.
*/
int MinAvg::solution(vector<int>& A)
{
    int start_idx = 0, win_start = 0, win_end = 1;
    double cur_avg = INT32_MAX;
    double min_avg = cur_avg;
    int a_size = static_cast<int>(A.size());  

    while ( win_start < win_end && win_end < a_size) {
        cur_avg = std::accumulate(A.begin() + win_start, A.begin() + win_end +1, 0) / static_cast<double>(win_end - win_start +1);
        
        if (cur_avg < min_avg) {
            min_avg = cur_avg;
            start_idx = win_start;
        }     
        if (win_end + 1 < a_size) {
            if ((A[win_end + 1] < cur_avg) || (win_end - win_start == 1)){
                ++win_end;
            }
            else {
                ++win_start;
            }
        }
        else {
            ++win_start;
        }
    }

    return start_idx;
}

/*Simple brute force solution which cheacks all the possible
* solutions.
*/
int MinAvg::solution_slow(vector<int>& A)
{
    int min_avg_idx = -1, idx = 1;
    double cur_avg = 0, min_avg = INT32_MAX;
    vector<double> prefix_sum(A.size() + 1, 0);
    for (auto num : A) {
        prefix_sum[idx] = num +  prefix_sum[idx - 1]; 
        ++idx;
    }

    for (int start_index = 1; start_index < static_cast<int>(prefix_sum.size()); ++start_index) {
        cur_avg = 0;
        for (int end_index = start_index + 1; end_index < static_cast<int>(prefix_sum.size()); ++end_index) {
            cur_avg = (prefix_sum[end_index] - prefix_sum[start_index - 1]) / static_cast<double>(end_index - (start_index - 1));
            if (cur_avg < min_avg) { 
                min_avg = cur_avg; 
                min_avg_idx = start_index - 1; 
            }
        }
    }
    return min_avg_idx;
}
