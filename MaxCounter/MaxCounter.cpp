#include "MaxCounter.h"

vector<int> MaxCounter::solution_one(int N, vector<int>& A)
{
    int current_max = 0;
    vector<int> counters(N, 0);

    for (auto timer : A) {
        if (timer <= N) {
            ++counters[timer - 1];
            current_max = max(current_max, counters[timer - 1]);
        }
        else {
            counters.assign(N, current_max);
        }
    }

    return counters;
}

vector<int> MaxCounter::solution_two(int N, vector<int>& A)
{
    int current_max = 0;
    int last_all_maxout = 0;
    vector<int> counters(N, 0);

    for (auto timer : A) {
        if (timer <= N) {
            if (counters[timer - 1] < last_all_maxout) {
                counters[timer - 1] = last_all_maxout + 1;
            }
            else {
                ++counters[timer - 1];
            }
           
            current_max = max(current_max, counters[timer - 1]);
        }
        else {
            last_all_maxout = current_max;
        }
    }

    for (int index = 0; index < (int)counters.size(); index++) {
        if (counters[index] < last_all_maxout) {
            counters[index] = last_all_maxout;
        }
    }

    return counters;
}
