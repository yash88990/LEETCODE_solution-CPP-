class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0); 
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            long long skip = (i + 1 < n) ? dp[i + 1] : 0;
            long long solve = points;
            if (i + brainpower + 1 < n) {
                solve += dp[i + brainpower + 1];  
            }
            dp[i] = max(skip, solve);
        }
        return dp[0];
    }
};
