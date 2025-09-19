class Solution {
public:
    int fib(int n) {
        //base case 
        if(n <= 1)return n;
        //step 1 ;- create a dp
        vector<int>dp(n+1 , -1);
        //step 2 ;- base case
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];  
    }
};