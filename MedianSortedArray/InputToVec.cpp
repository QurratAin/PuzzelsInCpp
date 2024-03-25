#include "pch.h"
#include "InputToVec.h"

void InputToVec::get_double_numbers_from_user()
{
	cout << "Please enter array of doubles."
		"The numbers should be separated by space." << endl;
	string numbers, one_number;;
	getline(cin, numbers);
	
	stringstream stream_of_numbers(numbers);
	
	while (stream_of_numbers >> one_number) {
		this->double_vector.push_back(stod(one_number));
	}
	
}

bool InputToVec::check_vector_sorted()
{
	return is_sorted(this->double_vector.begin(), this->double_vector.end());
}
