class Solution {
public:
    int minCost(vector<int>& cost, int i , vector<int>&dp) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        if (dp[i] != -1) return dp[i];
        
        return dp[i] = cost[i] + min(minCost(cost, i - 1 , dp), minCost(cost, i - 2 , dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1 , -1);
        return min(minCost(cost, n - 1 , dp), minCost(cost, n - 2 , dp));
    }
};