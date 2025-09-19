class Solution {
public:
    int solve(string& a , string& b , int i , int j , vector<vector<int>>&dp){
        //base case
        if( i == a.length() || j == b.length())return 0;
        int count = 0;
        //step 3 
        if(dp[i][j] != -1)return dp[i][j];
        if(a[i] == b[j])count = 1 + solve(a, b , i+ 1 , j+1 , dp);
        else count = max(solve(a ,b, i+1 , j , dp) , solve( a , b , i  ,j+1 , dp));
        //step 2 
        return dp[i][j] = count;
    }
    int longestCommonSubsequence(string text1, string text2) {
        //step 1 
        vector<vector<int>>dp(text1.size() , vector<int>(text2.size() , -1));
        return solve(text1 , text2 , 0 , 0 , dp);
    }
};