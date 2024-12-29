class Solution {
public:
int solve(vector<int> &cost , int n ){
    int prev1 = cost[1];
    int prev2 = cost[0];
    for(int i = 2  ; i < n ; i++){
        int curr = cost[i] + min(prev1 , prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1 , prev2);

}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost , n);
    }
};