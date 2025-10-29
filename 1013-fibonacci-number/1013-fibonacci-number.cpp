class Solution {
public:
    int solve(int n , vector<int>&dp){
        if(n == 0 || n ==  1)return n;
        //step 3 :- if ans is present -> return 
        if(dp[n] != -1)return dp[n];
        //step 2 :- store in dp 
    
        return dp[n] = solve(n-1 , dp) + solve(n-2 , dp);
    }
    int fib(int n) {

        // step 1 
        vector<int>dp(n+1 , -1);
        return solve(n , dp);
        
    }
};