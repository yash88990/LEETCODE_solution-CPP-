class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int nonzeroindex = 0;

        // First pass: Move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[nonzeroindex] = nums[i];
                nonzeroindex++;
            }
        }

        // Second pass: Fill the rest of the array with zeroes
        for (int i = nonzeroindex; i < n; i++) {
            nums[i] = 0;
        }
    }
}