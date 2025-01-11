class Solution {
public:
    bool canConstruct(string s, int k) {
        // If k is greater than the length of the string, return false
        if (k > s.length()) {
            return false;
        }

        // Count the frequency of each character in the string
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Count the number of characters with odd frequencies
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        // If the number of odd frequencies is greater than k, return false
        return oddCount <= k;
    }
};
