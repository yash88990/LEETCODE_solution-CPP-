import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int count = 0;

        // Count frequencies of each number
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        for (int num : nums) {
            // Check if current num and its complement (k - num) are available
            if (freq.getOrDefault(num, 0) > 0 && freq.getOrDefault(k - num, 0) > 0) {
                if (num == k - num) {
                    // Case: num + num = k (e.g., 2 + 2 = 4)
                    count += freq.get(num) / 2;
                    freq.put(num, 0);
                } else {
                    // Case: different numbers (e.g., 1 + 3 = 4)
                    int operations = Math.min(freq.get(num), freq.get(k - num));
                    count += operations;
                    freq.put(num, 0);
                    freq.put(k - num, 0);
                }
            }
        }

        return count;
    }
}