#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        // Map to store frequency of prefix sums mod k
        std::unordered_map<int, int> prefixSumModKFreq;
        // Initialize with 0 to handle case where prefix sum is directly divisible by k
        prefixSumModKFreq[0] = 1;
        
        int count = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            // Update prefix sum
            prefixSum += num;
            // Compute prefix sum mod k
            int mod = (prefixSum % k + k) % k;  // Ensure non-negative mod result
            
            // If this mod result has been seen before, add the frequency to count
            if (prefixSumModKFreq.find(mod) != prefixSumModKFreq.end()) {
                count += prefixSumModKFreq[mod];
            }
            
            // Update frequency of the current mod result
            prefixSumModKFreq[mod]++;
        }
        
        return count;
    }
};
