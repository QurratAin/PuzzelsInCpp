#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <filesystem>

using namespace std;

typedef vector<pair<int, string>> data_vector;
typedef vector<vector<string>> pyramid_vector;
/// <summary>
/// This function will read each line of a text file into 
/// vector of pairs.first will be an integer while the
/// second element will be a string. The read txt file 
/// should have a format like this.
///			1 abc
///			2 egd
///			7 bfg
///			<number><space><string>
///			...
/// </summary>
/// <param name="file_name"> name of the file which holds the data.</param>
/// <param name="data_read"> this gets populated with the data from file.</param>
void load_from_file(string file_name, data_vector& data_read) {

	if (filesystem::exists(filesystem::path(file_name))) {
		string current_line;
		ifstream msg_file(file_name.c_str());
		while (getline(msg_file, current_line)) {
			data_read.push_back(make_pair(
				atoi(current_line.substr(0, current_line.find(' ')).c_str()),
				current_line.substr(current_line.find(' ') + 1, string::npos)));
		}

	}
}


/// <summary>
/// The function check that data is not empty.
/// </summary>
/// <param name="data"> A vector of pairs with interger and string datatypes </param>
/// <returns> returns a bool true is data is valid else false </returns>
bool is_valid_input(data_vector& data) {
	return data.size() > 0 && !data.empty();
}

/// <summary>
/// This function takes the input read data which a vector of pairs. 
/// sort the vector inplace on the basis of integer number in the pair.
/// Then creates a vector of vectors(pyramid) with string data in the pair.
/// </summary>
/// <param name="data"> input data </param>
/// <param name="pyramid">pyramid gets populated from the data</param>
void create_pyramid(data_vector& data,
	pyramid_vector& pyramid) {

	std::sort(data.begin(), data.end(), [](auto& left, auto& right) {
		return left.first < right.first;
		});

	int start_idx = 0, number_to_push = 1;
	while (start_idx + number_to_push < data.size()) {
		vector<string> word;
		for (int i = start_idx; i < (start_idx + number_to_push); i++) {
			word.push_back(data[i].second);
		}
		pyramid.push_back(word);
		start_idx += number_to_push;
		number_to_push++;

	}
}

/// <summary>
/// This function reads from a message from a text file. 
/// the data file has a numberand word on each line.
/// if the data is valid then, it creates a pyramid of data.
/// at the end it decodes the message by concatenating all
/// the last word of each line of pyramid.
/// 
/// </summary>
/// <param name="message_file"> path to file which has encoded message </param>
/// <returns></returns>
string decode(string message_file) {

	string decoded_msg;
	data_vector encoded_data;
	load_from_file(message_file, encoded_data);

	if (is_valid_input(encoded_data)) {

		pyramid_vector pyramid;
		create_pyramid(encoded_data, pyramid);

		for (auto each_line : pyramid) {
			decoded_msg += each_line.back() + " ";
		}
	}
	else {
		decoded_msg = "The input file has error";
	}

	return decoded_msg;
}

/// <summary>
/// Given an encoded message file
/// example:
///			2 all
///			6 the
///			8 me
///			...
/// 
/// decode and output the message.
/// The encoding follows the pyramid form and the message is last word
/// of each row in the pyramid. 
/// example
///			1
///		2		3
/// 4		5		6
/// 
/// the decoded message will be the words with number 1, 3, 6.
///
/// </summary>
/// <returns></returns>
int main(int argc, char* argv[])
{
	if (argc > 1)
		cout << decode(argv[1]) << endl;

	return 0;
}
