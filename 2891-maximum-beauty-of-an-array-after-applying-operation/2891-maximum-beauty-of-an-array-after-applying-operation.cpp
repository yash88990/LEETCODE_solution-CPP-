class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> diff;
        
        // Step 1: Populate the difference map
        for (int num : nums) {
            diff[num - k]++;        // Start of the range
            diff[num + k + 1]--;    // End of the range (exclusive)
        }
        
        // Step 2: Sweep through the difference array
        int maxBeauty = 0, current = 0;
        for (auto& [_, count] : diff) {
            current += count;       // Update current overlap
            maxBeauty = max(maxBeauty, current); // Track maximum overlap
        }
        
        return maxBeauty;
    }
};
