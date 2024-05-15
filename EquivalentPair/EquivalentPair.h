#pragma once
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class EquivalentPair
{
private:
	map<pair<int, int>, int> dominoe_checker;
	
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes);

};

