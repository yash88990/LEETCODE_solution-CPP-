class Solution {
public:
    int solve(vector<int>&cost , int i , vector<int>&dp ){
        //base case
        if( i < 0)return 0;
        if( i == 0 || i == 1)return cost[i];
        //step3:- chekc ans is present or not
        if(dp[i] != -1)return dp[i];
        //step 2 :- store subproblems ans
        return dp[i] = cost[i] + min(solve(cost , i-1 , dp) , solve(cost , i-2 , dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //step1:- create a dp array
        vector<int>dp(n+1 , -1);
        return min(solve(cost , n-1 , dp) , solve(cost , n-2 , dp) );
    }
};