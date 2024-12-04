class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n = str1.size(), m = str2.size();
        
        while (i < n && j < m) {
            // Check if current character matches or matches the next cyclic character
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
                j++; // Move to the next character in str2
            }
            i++; // Always move to the next character in str1
        }
        
        // If we matched all characters in str2, return true
        return j == m;
    }
};
