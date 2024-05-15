#include "runningAverage.h"

double MovingAverage::calculate_average()
{
    double avg = 0;
    for (int index = 0; index < moving_window.size(); index++) {
        avg += moving_window[index];
    }
    return avg / moving_window.size();
}

double MovingAverage::next(int val)
{
    moving_window.push_front(val);
    if (moving_window.size() > window_size) {
        moving_window.pop_back();
    }
    return calculate_average();
}
