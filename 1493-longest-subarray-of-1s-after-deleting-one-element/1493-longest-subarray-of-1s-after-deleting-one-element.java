class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0, right = 0;
        int maxLen = 0;
        int zeroCount = 0;

        while (right < nums.length) {
            // If we encounter a zero, increment the counter
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds 1, shrink the window from the left
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Update maxLen. The window size is (right - left + 1).
            // Since we must delete one element, the length is (right - left).
            maxLen = Math.max(maxLen, right - left);
            right++;
        }

        return maxLen;
    }
}