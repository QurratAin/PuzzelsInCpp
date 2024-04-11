#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class frequency
{
	private:
		unordered_multimap<int, int> hash_map;
	public:
		void create_map(vector<int> input_numbers);
		void max_duplicate_key(int &frequency, int &element);
};

