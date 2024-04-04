#include "Median.h"

void Median::calculate_median()
{
	vector<double> merged_number;
	int idx_of_first = 0, idx_of_second = 0;

	// merge by checking which number is smallest on the each number array
	while (idx_of_first < this->first.size() && idx_of_second < this->second.size()) {
		if (this->first[idx_of_first] < this->second[idx_of_second]) {
			merged_number.push_back(this->first[idx_of_first]);
			++idx_of_first;
		}
		else {
			merged_number.push_back(this->second[idx_of_second]);
			++idx_of_second;
		}
	}

	// if numbers are remaining on first array, add those
	if (idx_of_first != this->first.size()) {
		std::for_each(this->first.begin() + idx_of_first, this->first.end(),
			[&merged_number](double n) { merged_number.push_back(n); });
	}

	// if numbers are remaining on the seconf array, add those
	if (idx_of_second != this->second.size()) {
		std::for_each(this->second.begin() + idx_of_second, this->second.end(),
			[&merged_number](double n) {merged_number.push_back(n); });
	}

	// check size of merged array is even or odd
	// and calucualte median
	if (merged_number.size() % 2 == 0) {
		int middle_index = (int)merged_number.size() / 2;
		this->median = (merged_number[middle_index - 1] + merged_number[middle_index]) / 2;
	}
	else {
		int middle_index = (int)floor(merged_number.size() / 2);
		this->median = merged_number[middle_index];
	}

}