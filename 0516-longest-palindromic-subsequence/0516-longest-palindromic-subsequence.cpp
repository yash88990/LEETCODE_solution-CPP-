class Solution {
public:
    int solve(string& a , string& b , int i , int j , vector<vector<int>>&dp){
        //base case
        if( i == a.length() || j == b.length())return 0;
        int count = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(a[i] == b[j])count = 1 + solve(a, b , i+ 1 , j+1 , dp);
        else count = max(solve(a ,b, i+1 , j , dp) , solve( a , b , i  ,j+1 , dp));
        return dp[i][j] = count;
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());

        vector<vector<int>>dp(s.length() , vector<int>(s.length() , -1));
        return solve(s , s2 , 0 , 0 , dp);
        
    }
};