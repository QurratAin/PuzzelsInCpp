#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class LongestSubstring
{
private:
    int findLength(string s);
public:
    int lengthOfLongestSubstring(string s);
    int SlidingWindowLength(string s);
};

