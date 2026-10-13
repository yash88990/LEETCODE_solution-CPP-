class Solution {
public:
    int solve(int n , vector<int>&dp){
        //base case
        if ( n == 0)return 0;
        if( n == 1 || n == 2)return 1 ;
        // check if present
        if(dp[n] != -1)return dp[n];
        //recc and memo
        return dp[n] = solve(n-1 , dp) + solve(n-2 , dp) + solve(n-3 , dp);

    }
    int tribonacci(int n) {
        //create a dp
        vector<int>dp(n+1, -1);
        return solve(n , dp);
    }
};