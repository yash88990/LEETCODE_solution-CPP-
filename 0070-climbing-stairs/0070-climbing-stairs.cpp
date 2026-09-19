class Solution {
public:
    int climbStairs(int n) {
        int prev1=1 , prev2=0;
        if(n<=1)return n;
        int cnt = 1 ;
        while(cnt <= n ){
            int curr = prev1 + prev2;
            prev2=prev1;
            prev1=curr;
            cnt++;
        }
        return prev1;
    }
};