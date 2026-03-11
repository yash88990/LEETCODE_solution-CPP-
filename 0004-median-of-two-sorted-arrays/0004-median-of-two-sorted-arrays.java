import java.util.*;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        // Step 1: Merge both arrays
        int[] merged = new int[nums1.length + nums2.length];

        int index = 0;
        for (int num : nums1) {
            merged[index++] = num;
        }

        for (int num : nums2) {
            merged[index++] = num;
        }

        // Step 2: Sort merged array
        Arrays.sort(merged);

        // Step 3: Find median
        int n = merged.length;

        if (n % 2 == 1) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
}