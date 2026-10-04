class Solution {
public:
    // int solve(vector<int>&cost , int i, vector<int>&dp){
    //     if(i < 0)return 0;
    //     if(i <= 1)return cost[i];
    //     //step 3 ;- if ans then return
    //     if(dp[i] != -1)return dp[i];

    //     //step 2 - save the ans
    //     return dp[i] = cost[i] + min(solve(cost , i-1,dp) , solve(cost, i-2,dp));

    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0)return 0;
        if(n ==  1)return cost[0];
        //step 1 
        vector<int>dp(n+1 , -1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i = 2 ;i < n ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1] , dp[n-2]);


    }
};