#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class RomanToIntegerI {
private:
    unordered_map<char, int> symbol_map = { {'I', 1}, {'V', 5},
                                            {'X', 10}, {'L', 50},
                                            {'C', 100},{'D', 500},
                                            {'M', 1000} };
public:
    int romanToInt(string s);
};

class RomanToIntegerII {
private:
    unordered_map<char, int> symbol_map = { {'I', 1}, {'V', 5},
                                            {'X', 10}, {'L', 50},
                                            {'C', 100},{'D', 500},
                                            {'M', 1000} };
public:
    int romanToInt(string s);
};

