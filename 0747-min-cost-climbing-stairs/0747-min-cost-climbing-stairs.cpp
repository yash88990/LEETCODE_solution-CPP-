class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0)return 0;
        if(n == 1)return cost[0];
        int prev1 = cost[1] , prev2 = cost[0];
        for(int i = 2 ;i < n ; i++){
            int curr = cost[i] + min(prev2 , prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev2 , prev1);
    }
};