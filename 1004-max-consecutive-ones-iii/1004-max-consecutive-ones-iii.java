class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.length; i++) {
            // If we encounter a zero, increment the counter
            if (nums[i] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds k, shrink the window from the left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Calculate the window size and update maxLength
            maxLength = Math.max(maxLength, i - left + 1);
        }

        return maxLength;
    }
}