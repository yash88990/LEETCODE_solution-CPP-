class Solution {
public:
    int solvememo(int n , vector<int>&dp){
        if(n<= 1)return n;
        //step 3:- check ans exists or not
        if(dp[n] != -1)return dp[n];
        
        //step 2:- store subproblem ans
        return dp[n] = solvememo(n-1 , dp) + solvememo(n-2 , dp); 

    }

    int fib(int n) {
        //step 1 :- create a dp arrya of size (n+1)
        vector<int>dp(n+1 , -1);
        return solvememo(n , dp);
    }
};