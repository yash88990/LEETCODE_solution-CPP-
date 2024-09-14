class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Step 1: Find the maximum value in the array
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 2: Find the length of the longest contiguous subarray where all elements are max_val
        int longest = 0, current_len = 0;
        for (int num : nums) {
            if (num == max_val) {
                // Continue counting the length of the current subarray
                current_len++;
                longest = max(longest, current_len);
            } else {
                // Reset the current length when the streak breaks
                current_len = 0;
            }
        }
        
        return longest;
    }
};
