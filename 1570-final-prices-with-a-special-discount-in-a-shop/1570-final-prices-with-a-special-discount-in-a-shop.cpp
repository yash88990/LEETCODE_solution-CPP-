class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);
        
        for (int i = 0; i < n; ++i) {
            answer[i] = prices[i]; // Default price without discount
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    answer[i] = prices[i] - prices[j]; // Apply discount
                    break;
                }
            }
        }
        
        return answer;
    }
};
