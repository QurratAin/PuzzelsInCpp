// MostFreq.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Find the most frequently occurring item in an array.

//Example: The most frequently occurring item 
// in [1, 3, 1, 3, 2, 1] is 1.

#include <iostream>
#include <vector>
#include "frequency.h"
#include "Utils.h"

int main()
{
    //get input from user
    vector<int> input_numbers;
    ConsoleInput::string_to_vec<int>("Please enter an array of integers"
        "numbers which are seperated by space", input_numbers);

    //Find most frequent element in array
    frequency data;
    data.create_map(input_numbers);
    int freq = -1; 
    int element;
    data.max_duplicate_key(freq, element);
    cout << "The most frequent element is " << element <<
        ", with the frequency of " << freq << endl;
}

