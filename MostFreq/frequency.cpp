#include "frequency.h"

void frequency::create_map(vector<int> input_numbers)
{
	for (int index = 0; index < input_numbers.size(); index++) {
        if (hash_map.contains(input_numbers[index])) {
            ++hash_map[input_numbers[index]];
        }
        else {
            hash_map.insert({ input_numbers[index], 1 });
        }
	}
}

void frequency::max_duplicate_key(int &frequency, int &element)
{
    frequency = -1;
    // get the element with highest frequency
    for (auto [key, value] : hash_map) {
        if (value > frequency) {
            frequency = value;
            element = key;
        }
    }

}
