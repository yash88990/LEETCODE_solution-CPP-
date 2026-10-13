class Solution {
public:
    int solve(vector<int>&prices , int fee , vector<vector<int>>&dp , int i , int canbuy){
        if(i == prices.size())return 0;
        if(dp[i][canbuy] != -1)return dp[i][canbuy];
        int profit = 0;
        if(canbuy){
            int buy = -prices[i] + solve(prices , fee, dp , i+1 , 0);
            int skip = solve(prices  , fee, dp , i+1 , 1);
            profit = max(buy , skip);
        }else{
            int sell = prices[i] - fee + solve(prices , fee, dp , i+ 1 , 1);
            int hold = solve(prices , fee, dp , i+ 1 , 0);
            profit = max(sell, hold);
        }
        return dp[i][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices , fee , dp , 0 , 1);
    }
};