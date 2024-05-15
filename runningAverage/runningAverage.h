#pragma once

#include <iostream>
#include <deque>

using namespace std;

class MovingAverage {
private:
    std::deque<double> moving_window;
    int window_size;
public:
    MovingAverage(int size) {
        window_size = size;
    }

    double calculate_average();
    double next(int val);
};