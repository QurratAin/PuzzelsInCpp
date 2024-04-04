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