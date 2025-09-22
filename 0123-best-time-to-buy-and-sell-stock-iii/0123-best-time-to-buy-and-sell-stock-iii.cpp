#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        // Arrays to store the maximum profit up to each day
        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n, 0);

        // Compute leftProfit
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i-1], prices[i] - minPrice);
        }

        // Compute rightProfit
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i+1], maxPrice - prices[i]);
        }

        // Combine the two profits
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxProfit;
    }
};