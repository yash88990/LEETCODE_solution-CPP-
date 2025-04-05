#include <vector>

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        return subsetXORSumHelper(nums, 0, 0);
    }

private:
    int subsetXORSumHelper(std::vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            // When we've considered all elements, return the current XOR total
            return currentXOR;
        }

        // Calculate the sum of XOR totals including the current element
        int includeCurrent = subsetXORSumHelper(nums, index + 1, currentXOR ^ nums[index]);
        
        // Calculate the sum of XOR totals excluding the current element
        int excludeCurrent = subsetXORSumHelper(nums, index + 1, currentXOR);
        
        // Return the sum of both possibilities
        return includeCurrent + excludeCurrent;
    }
};