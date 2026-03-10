class Solution {
    public int pivotIndex(int[] nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Step 1: Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Iterate to find the pivot point
        for (int i = 0; i < nums.length; i++) {
            // Right sum is (totalSum - leftSum - nums[i])
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
}