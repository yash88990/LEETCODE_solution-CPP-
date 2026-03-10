class Solution {
    public boolean isSubsequence(String s, String t) {
        int sIndex = 0;
        int tIndex = 0;

        // Traverse both strings using two pointers
        while (sIndex < s.length() && tIndex < t.length()) {
            // If characters match, move the s pointer
            if (s.charAt(sIndex) == t.charAt(tIndex)) {
                sIndex++;
            }
            // Always move the t pointer
            tIndex++;
        }

        // If sIndex reached the end of s, then s is a subsequence of t
        return sIndex == s.length();
    }
}