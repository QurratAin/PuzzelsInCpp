#include "LongestSubstring.h"

int LongestSubstring::lengthOfLongestSubstring(string s)
{
    if (s.empty()) {
        return 0;
    }
    vector<int> all_lengths;
    for (int idx = 0; idx < s.size(); idx++) {
        all_lengths.push_back(findLength(s.substr(idx)));
    }

    return *std::max_element(all_lengths.begin(), all_lengths.end());
}

int LongestSubstring::findLength(string s) {
    vector<string> all_substrings;
    vector<int> size_of_sub_strings;
    string sub_string;
    unordered_map<char, int> letter_finder;

    for (int idx = 0; idx < s.size(); idx++) {
        if (letter_finder.find(s[idx]) != letter_finder.end()) {
            all_substrings.push_back(sub_string);
            size_of_sub_strings.push_back(sub_string.size());
            sub_string.clear();
            letter_finder.clear();
        }
        sub_string.push_back(s[idx]);
        letter_finder.insert({ s[idx], idx });
    }
    //last substring
    all_substrings.push_back(sub_string);
    size_of_sub_strings.push_back(sub_string.size());

    return *std::max_element(size_of_sub_strings.begin(), size_of_sub_strings.end());
}

int LongestSubstring::SlidingWindowLength(string s) {

    int window_length = 0;
    int start_window_idx = 0, end_window_idx = 0, current_char_idx = 0;
    unordered_map<char, int> letter_finder;

    for (auto letter : s) {
        if (letter_finder.find(letter) != letter_finder.end()) {
            // letter found
            int found_letter_position = letter_finder.at(letter);
            vector<int> keys_to_delete;
            for (auto [key, value] : letter_finder) {
                if (value <= found_letter_position) {
                    keys_to_delete.push_back(key);
                }
            }
            for (auto k : keys_to_delete) letter_finder.erase(k);
            start_window_idx = found_letter_position + 1;
        }
        letter_finder.insert({ letter, current_char_idx });
        end_window_idx++;
        window_length = max(window_length, end_window_idx - start_window_idx);
        ++current_char_idx;

    }

    return window_length;

}