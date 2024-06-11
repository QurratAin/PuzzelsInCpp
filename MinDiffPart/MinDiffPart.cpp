#include "MinDiffPart.h"
// first calculate the sum of whole array
// then iterate over the array while subtracting the current
// position element from the right_sum and adding the element
// in left_sum. Also maintain a minimum diff variable in the loop.
int MinDiffPart::find_partition_point(vector<int>& input)
{
    std::valarray<int> input_valarray{ input.data(), input.size() };
    long int right_sum = (long int)input_valarray.sum() - input[0];
    long int left_sum = input[0];
    long int min_diff = LONG_MAX;

    for (int partition = 1; partition < (int)input.size(); partition++) {
        min_diff = std::min(min_diff, std::abs(left_sum - right_sum));
        right_sum -= input[partition];
        left_sum += input[partition];
    }

    return (int)min_diff;    
}
