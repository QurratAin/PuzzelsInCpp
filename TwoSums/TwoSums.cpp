// TwoSums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Util.h"
#include "FindSum.h"

int main()
{
    //get input from user
    vector<int> input_numbers;
    ConsoleInput::string_to_vec<int>("Please enter an array of double" 
        "numbers which are seperated by space", input_numbers);
    int target_sum{};
    cout << "Please enter intger target sum :";
    cin >> target_sum;

    //Find Sum in array
    FindSum data;
    vector<int> result = data.check(input_numbers, target_sum);
    if (result.size() == 2) {
        cout << "Number ["<< result[0] << "] = " << input_numbers[result[0]]
            << " and number [" << result[1] << "] = "<< input_numbers[result[1]] 
            << " , forms the target sum."<< endl;
    }
    else {
        cout << "Target Sum not found";
    }
}
