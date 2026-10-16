class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int minprice = prices[0];
        for(int i = 0 ; i < n; i++){
            minprice = min(minprice , prices[i]);
            int profit = prices[i] - minprice;
            ans = max(ans , profit);
            
        }
        return ans;
    }
};