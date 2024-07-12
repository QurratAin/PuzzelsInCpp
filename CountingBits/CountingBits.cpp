#include "CountingBits.h"

int CountingBits::counting_bits_boolvec(int X, vector<int>& A)
{
    std::vector<bool> leaf_counter(X + 1);
    leaf_counter[0] = true;

    for (int time = 0; time < (int)A.size(); time++) {
        if (A[time] < ( X + 1)) {
            leaf_counter[A[time]] = true;
            if (std::all_of(leaf_counter.cbegin(), leaf_counter.cend(), [](bool i) {return i; })) {
                // all positions are set to jump
                return time;
            }
        }
        
    }

    return -1;

}

int CountingBits::counting_bits_boolarray(int X, vector<int>& A)
{
    int one_index_size = X + 1;
    bool *leaf_counter = new bool[one_index_size]();
    leaf_counter[0] = true;
    int fill_counter = 0;

    for (int time = 0; time < (int)A.size(); time++) {
        if (A[time] <= one_index_size && !leaf_counter[A[time]]) {
            
            leaf_counter[A[time]] = true;
            ++fill_counter;
            if (fill_counter >= X) {
                delete[] leaf_counter;
                return time;
            }                            
        }

    }
    delete [] leaf_counter;
    return -1;
}


int CountingBits::counting_bits_bitflip(int X, vector<int>& A)
{
    long long unsigned int target_leaf_counter = static_cast<unsigned long long>(pow(2, X)) - 1ULL;
    long long unsigned int leaf_counter = 0;
    
    for (int time = 0; time < (int)A.size(); time++) {
        if (A[time] <= (X + 1)) {
            leaf_counter |= 1ULL << (static_cast<unsigned long long>(A[time]) - 1ULL);
            if ((leaf_counter & target_leaf_counter) == target_leaf_counter) {
                return time;
            }
        }
    }

    return -1;

}

int CountingBits::counting_bits_hash(int X, vector<int>& A)
{
    unordered_map<int, int> leaf_counter;
    for (int time = 0; time < (int)A.size(); time++) {
        if (A[time] <= X) {
            if (!leaf_counter.contains(A[time])) {
                //element not found
                leaf_counter.insert({ A[time], time });
                if (static_cast<int>(leaf_counter.size()) == X) {
                    return time;
                }
            }
        }
    }
    
    return -1;
}

int CountingBits::counting_bits_set(int X, vector<int>& A)
{
    unordered_set<int> leaf_counter;
    for (int time = 0; time < (int)A.size(); time++) {
        if (A[time] <= X) {
            leaf_counter.insert(A[time]);
            if (static_cast<int>(leaf_counter.size()) == X) {
                return time;
            }
        }
    }

    return -1;
}