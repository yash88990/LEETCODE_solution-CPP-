class Solution {
public:
    int solve(int i  , int j , string &t1 , string &t2 , vector<vector<int>>&dp){
        if(i == t1.size() || j == t2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(t1[i] == t2[j])return 1 + solve(i+1 , j+1 , t1,t2,dp);
        int skip1 = solve(i+1, j , t1 , t2 , dp);
        int skip2 = solve(i , j+1 , t1 , t2 , dp);
        return dp[i][j] = max(skip1,skip2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0 ,0 , text1 , text2 , dp);
    }
};