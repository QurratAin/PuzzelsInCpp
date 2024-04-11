#pragma once
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/// <summary>
/// Struct to convert console input to desired datatype
/// </summary>
struct ConsoleInput {
public:
	template<typename T>
	static void string_to_vec(string msg_to_user, vector<T>& input_vector) {
		cout << msg_to_user << endl;

		string input_string;
		getline(cin, input_string);

		T single_entry{};
		stringstream stream_of_numbers(input_string);

		while (stream_of_numbers >> single_entry) {
			input_vector.push_back(single_entry);
		}
	};

};