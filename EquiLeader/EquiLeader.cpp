#include "EquiLeader.h"

void EquiLeader::find_leader(vector<int>& A_array, int &leader, int &frequency) {
    // Create a frequency map
    unordered_map<int, int> leader_map;
    leader = -1;
    frequency = 0;
    for (int index = 0; index < static_cast<int>(A_array.size()); ++index) {
        if (leader_map.contains(A_array[index])) {
            ++leader_map[A_array[index]];
        }
        else {
            leader_map.insert({ A_array[index], 1 });
        }
    }
    // get the element with highest frequency
    for (auto [key, value] : leader_map) {
        if (value > static_cast<int>(A_array.size() / 2) &&
            frequency < value) {
            frequency = value;
            leader = key;
        }
    }
}


/* This approach first create a hashmap to find the leader.
* After that goes over the array, calculating leader's 
* occurance.
*/
int EquiLeader::solution(vector<int>& A)
{
    // find the leader of whole array
    int array_size = static_cast<int>(A.size());
    int whole_array_leader = 0, freq = 0;
    find_leader(A, whole_array_leader, freq);
    int leader_count_left = 0, seq_count = 0;

    // go over all the array to count leader 
    for (int index = 0; index < array_size; ++index) {
        if (A[index] == whole_array_leader) {
            ++leader_count_left;
        }
        if (leader_count_left > ( (index + 1) / 2) &&
            (freq - leader_count_left) > ((array_size - (index + 1))/2) ) {
            ++seq_count;
        }
    }

    return seq_count;
}

/* implement the stack approach to find leader. As we are going 
* through the array to find leader, we are saving the leader
* at each element. 
* 
*/
int EquiLeader::solution_slow(vector<int>& A)
{
    int leader;
    int stack_size = 0;
    int cur_array_size = 0;
    int seq_count = 0;
    int a_size = static_cast<int>(A.size());
    // the last element will be the leader of whole array
    vector<int> record_leaders(a_size, 0);
    for (auto itr = A.begin(); itr != A.end(); ++itr) {
        if (stack_size == 0) {
            ++stack_size;
            leader = *itr;
        }
        else if (leader != *itr) {
            --stack_size;
        }
        else {
            ++stack_size;
        }
    
        if (stack_size > 0 && 
            std::count(A.begin(), itr + 1, leader) > static_cast<int>((cur_array_size + 1) / 2)) {
            record_leaders[cur_array_size] = leader;
        }
        else {
            record_leaders[cur_array_size] = -1;
        }
        ++cur_array_size;
    }
    
    int whole_array_leader = record_leaders.back();
    if (whole_array_leader != -1) { 
        // leader to whole array exists
        auto same_leader = std::find(record_leaders.begin(), record_leaders.end()-1, whole_array_leader);
        while(same_leader != record_leaders.end()-1){        
            // find other sequence has same leader
            int div_pos = same_leader - record_leaders.begin();
            int count = std::count(A.begin() + div_pos + 1, A.end(), whole_array_leader);
            int sub_seq_array_size = static_cast<int>((a_size -(div_pos + 1))/ 2);
         
            if ( count > sub_seq_array_size) {
                ++seq_count;
            }
            same_leader = std::find(std::next(same_leader), record_leaders.end()-1, whole_array_leader);
        }
    }

    return seq_count;
}
