#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        // Step 1: Count the frequency of each element
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Sort the elements by frequency and then by value
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b; // If frequencies are the same, sort by value in decreasing order
            return freq[a] < freq[b]; // Otherwise, sort by frequency in increasing order
        });
        
        return nums;
    }
};
