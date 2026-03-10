import java.util.*;

class Solution {
    public boolean closeStrings(String word1, String word2) {
        // Condition 1: Lengths must be equal
        if (word1.length() != word2.length()) {
            return false;
        }

        // Use maps to store frequency of characters
        Map<Character, Integer> count1 = new HashMap<>();
        Map<Character, Integer> count2 = new HashMap<>();
        
        // Use sets to store unique characters
        Set<Character> chars1 = new HashSet<>();
        Set<Character> chars2 = new HashSet<>();

        for (char c : word1.toCharArray()) {
            count1.put(c, count1.getOrDefault(c, 0) + 1);
            chars1.add(c);
        }

        for (char c : word2.toCharArray()) {
            count2.put(c, count2.getOrDefault(c, 0) + 1);
            chars2.add(c);
        }

        // Condition 2: Both strings must have the same set of unique characters
        if (!chars1.equals(chars2)) {
            return false;
        }

        // Condition 3: Sorted frequencies must be the same
        List<Integer> freq1 = new ArrayList<>(count1.values());
        List<Integer> freq2 = new ArrayList<>(count2.values());

        Collections.sort(freq1);
        Collections.sort(freq2);

        return freq1.equals(freq2);
    }
}