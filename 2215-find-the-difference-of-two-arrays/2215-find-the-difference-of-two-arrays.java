import java.util.*;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        // Create sets to store unique elements of each array
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1) set1.add(num);
        
        Set<Integer> set2 = new HashSet<>();
        for (int num : nums2) set2.add(num);

        List<Integer> difference1 = new ArrayList<>();
        List<Integer> difference2 = new ArrayList<>();

        // Find elements in nums1 not in set2
        for (int num : set1) {
            if (!set2.contains(num)) {
                difference1.add(num);
            }
        }

        // Find elements in nums2 not in set1
        for (int num : set2) {
            if (!set1.contains(num)) {
                difference2.add(num);
            }
        }

        // Return as a list of lists
        return Arrays.asList(difference1, difference2);
    }
}