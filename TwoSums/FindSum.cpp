#include "FindSum.h"

vector<int> FindSum::check(vector<int>& nums, int target) {
    for (int idx = 0; idx < nums.size(); idx++) {
        int number_to_find = target - nums[idx];
        auto number_pos = std::find(nums.begin(), nums.end(), number_to_find);
        if (nums.end() != number_pos) {
            int found_number_index = number_pos - nums.begin();
            if (found_number_index != idx) {
                return vector<int>{idx, found_number_index};
            }
        }
    }
    return vector<int>{};
}

vector<int> FindSum::check_by_hash(vector<int>& nums, int target)
{
    unordered_map<int, int> diff_map;
    for (int idx = 0; idx < nums.size(); idx++) {
        if (diff_map.find(target - nums[idx]) != diff_map.end()) {
           return vector<int>{diff_map.at(target - nums[idx]), idx};
        }
        diff_map.insert({ nums[idx], idx });
    }

    return vector<int>();
}
