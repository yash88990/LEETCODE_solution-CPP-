class Solution {
    public boolean increasingTriplet(int[] nums) {
        // Use Integer.MAX_VALUE to mirror C++ INT_MAX
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;

        for (int num : nums) {
            if (num <= first) {
                first = num; // new smallest
            } else if (num <= second) {
                second = num; // num is bigger than first but smaller than second
            } else {
                // num > first and num > second -> triplet exists
                return true;
            }
        }

        return false;
    }
}