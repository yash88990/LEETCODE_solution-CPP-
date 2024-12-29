#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        // Frequency count of characters at each position in words
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int i = 0; i < n; ++i) {
                freq[word[i] - 'a'][i]++;
            }
        }

        // DP array to store the number of ways to form target up to index i
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to form an empty target

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we skip the current column in words
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;

                if (i < m && freq[target[i] - 'a'][j] > 0) {
                    // If we use the current column in words to form target[i]
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * freq[target[i] - 'a'][j]) % MOD;
                }
            }
        }

        return dp[m][n];
    }
};
