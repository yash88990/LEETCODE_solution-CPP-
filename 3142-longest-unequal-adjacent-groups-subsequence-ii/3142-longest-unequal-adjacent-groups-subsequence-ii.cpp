class Solution {
public:
    // Check if hamming distance between a and b is exactly 1
    bool isDistance1(const string& a, const string& b) {
        if (a.size() != b.size()) return false;

        int diffCount = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != b[i]) diffCount++;
            if (diffCount > 1) return false;
        }
        return diffCount == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = (int)words.size();
        // dp[i] will hold the indices of the longest valid subsequence ending at i
        vector<deque<int>> dp(n);

        // Initialize dp: each subsequence at least contains itself
        for (int i = 0; i < n; i++) {
            dp[i].push_back(i);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j]) continue;
                if (!isDistance1(words[i], words[j])) continue;

                if ((int)dp[j].size() + 1 > (int)dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(i);
                }
            }
        }

        // Find the longest subsequence among all dp[i]
        int maxLength = 0;
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if ((int)dp[i].size() > maxLength) {
                maxLength = (int)dp[i].size();
                maxIndex = i;
            }
        }

        // Convert indices to actual words
        vector<string> result;
        for (int idx : dp[maxIndex]) {
            result.push_back(words[idx]);
        }

        return result;
    }
};
