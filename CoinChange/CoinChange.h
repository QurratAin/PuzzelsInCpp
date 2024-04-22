#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//You are given an integer array coins representing coins of 
// different denominations and an integer amount representing 
// a total amount of money. Return the fewest number of coins 
// that you need to make up that amount. If that amount of money 
// cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

class CoinChange
{
private:
    int solveMemoization(vector<int>& coins, int amount, vector<int>& dp);
public:
    int find(vector<int>& coins, int amount);
};

