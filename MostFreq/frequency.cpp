#include "frequency.h"

void frequency::create_map(vector<int> input_numbers)
{
	for (int index = 0; index < input_numbers.size(); index++) {
		hash_map.insert(pair<int, int> (input_numbers[index], index));
	}
}

void frequency::max_duplicate_key(int &frequency, int &element)
{
	frequency = -1;
	for (int bucket_num = 0; bucket_num < hash_map.bucket_count(); bucket_num++ ) {
		
		if (frequency < static_cast<int>(hash_map.bucket_size(bucket_num))) {
			frequency = static_cast<int>(hash_map.bucket_size(bucket_num));
			auto target_bucket = hash_map.begin(bucket_num);
			element = target_bucket->first;
		}
	}
}
