class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double currentSum = 0.0;
        
        // Step 1: Calculate sum of the first window
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }

        double maxSum = currentSum;

        // Step 2: Slide the window across the array
        for (int i = k; i < nums.length; ++i) {
            // Add the new element and subtract the one that left the window
            currentSum += nums[i] - nums[i - k];
            maxSum = Math.max(maxSum, currentSum);
        }

        // Return the average
        return maxSum / k;
    }
}