class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitMask = 0, maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            while ((bitMask & nums[right]) != 0) { 
                bitMask ^= nums[left];  // Remove nums[left] from bitMask
                left++;  // Shrink window
            }
            bitMask |= nums[right];  // Add nums[right] to bitMask
            maxLength = max(maxLength, right - left + 1);  // Update max length
        }
        
        return maxLength;
    }
};
