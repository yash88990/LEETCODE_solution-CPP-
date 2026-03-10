import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        // Map to store frequency of each number
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : arr) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        // Set to track unique frequency counts
        Set<Integer> uniqueCounts = new HashSet<>();
        for (int count : countMap.values()) {
            // If the count is already in the set, it's not unique
            if (uniqueCounts.contains(count)) {
                return false;
            }
            uniqueCounts.add(count);
        }

        return true;
    }
}