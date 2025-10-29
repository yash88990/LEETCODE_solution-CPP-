class Solution {
public:
    int solve(string &a , string &b , int i , int j , vector<vector<int>>&dp){
        if(i == a.size() || j == b.size())return 0;
       
        if(dp[i][j] != -1)return dp[i][j];
        
        int count = 0;
        if(a[i] == b[j]){
            count = 1 + solve(a , b , i + 1 , j + 1 , dp);
        }else{
            count = max(solve(a , b , i + 1 , j , dp) , solve(a , b , i , j + 1 , dp));
        }
        return dp[i][j] =  count;
    }
    int longestPalindromeSubseq(string s) {
        string revstr = s;
        reverse(revstr.begin() , revstr.end());
        vector<vector<int>>dp(s.size() , vector<int>(s.size() , -1));
        return solve(s , revstr , 0 , 0 , dp);

        
    }
};