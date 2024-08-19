class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0; // If n is 1, no operations are needed.
        
        vector<int> dp(n + 1, 0); // DP array to store the minimum steps for each number of A's
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i; // In the worst case, it takes i operations (Copy All, Paste (i-1) times)
            for (int j = i / 2; j >= 1; --j) {
                if (i % j == 0) { // If j is a divisor of i
                    dp[i] = dp[j] + (i / j); // The minimum steps to get i A's
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
