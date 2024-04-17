#include "equalFrequency.h"


bool equalFrequency::calculate(string word)
{
    // create a hash multimap of string
    unordered_multimap<char, int> word_map;
    for (int index = 0; index < word.size(); index++) {
        word_map.insert(pair<char, int>(word[index], index));
    }

    vector<int> freq;
    for (int bucket_num = 0; bucket_num < static_cast<int> (word_map.bucket_count()); bucket_num++) {
        int new_freq = static_cast<int>(word_map.bucket_size(bucket_num));
        // get the frequencies in buckets
        if (new_freq > 0) {
            freq.push_back(new_freq);
        }
    }

    // sort and find unique
    sort(freq.begin(), freq.end());
    vector<int> unique_freq = freq;
    unique_freq.erase(unique(unique_freq.begin(), unique_freq.end()), unique_freq.end());

    if (freq.size() == 1) {
        return true;
    }
    // too many difference frequencies, cant be equlaize with 1 removal
    if (unique_freq.size() > 2 || (unique_freq.size() == 1 && unique_freq[0] != 1)) {
        return false;
    }

    if (unique_freq.size() == 1 && unique_freq[0] == 1) {
        return true;
    }
    // checking when there are 2 unique frequencies 
    vector<int> count;
    int counter = 1;
    for (int index = 0; index < freq.size() - 1; index++) {
        if (freq[index] == freq[index + 1]) {
            counter++;
        }
        else {
            count.push_back(counter);
            counter = 1;
        }
    }
    count.push_back(counter);

    // if count doesn't have one, it isn't editable
    if (count[0] != 1 && count[1] != 1) {
        return false;
    }

    if ((count[0] == 1 && unique_freq[0] == 1) || 
        (count[1] == 1 && unique_freq[1] == 1) ||
        (count[0] == 1 && (unique_freq[0] - unique_freq[1] == 1)) ||
        count[1] == 1 && ((unique_freq[1] - unique_freq[0] == 1)) ) {
        return true;
    }

    return false;
}
