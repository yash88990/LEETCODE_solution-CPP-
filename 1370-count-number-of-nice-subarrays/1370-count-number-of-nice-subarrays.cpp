#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixCount;
        int currentOddCount = 0;
        int result = 0;
        
        // Initialize with prefix count 0 having one occurrence
        prefixCount[0] = 1;
        
        for (int num : nums) {
            if (num % 2 == 1) {
                currentOddCount++;
            }
            
            if (prefixCount.find(currentOddCount - k) != prefixCount.end()) {
                result += prefixCount[currentOddCount - k];
            }
            
            prefixCount[currentOddCount]++;
        }
        
        return result;
    }
};
