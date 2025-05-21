class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit =0;
        for(int i = 1 ; i < prices.size() ; i++){
            minprice = min(minprice , prices[i]);
            int profit = prices[i] - minprice;
            maxprofit = max(maxprofit , profit);

        }
        return maxprofit;
    }
};