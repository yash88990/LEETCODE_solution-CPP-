class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstOccurrence(26, -1);
        vector<int> lastOccurrence(26, -1);
        
        // Record the first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            if (firstOccurrence[s[i] - 'a'] == -1) {
                firstOccurrence[s[i] - 'a'] = i;
            }
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        int count = 0;
        // Check for palindromic subsequences
        for (int ch = 0; ch < 26; ++ch) {
            int start = firstOccurrence[ch];
            int end = lastOccurrence[ch];
            if (start != -1 && end - start > 1) {
                // Count distinct characters between start and end
                unordered_set<char> uniqueChars;
                for (int i = start + 1; i < end; ++i) {
                    uniqueChars.insert(s[i]);
                }
                count += uniqueChars.size();
            }
        }
        return count;
    }
};
