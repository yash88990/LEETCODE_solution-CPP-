#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int hold = INT_MIN; // Maximum profit if we hold a stock
        int cash = 0; // Maximum profit if we have cash
        
        for (int price : prices) {
            int prevHold = hold;
            hold = std::max(hold, cash - price - fee); // Update hold
            cash = std::max(cash, prevHold + price); // Update cash
        }
        
        return cash; // Return maximum profit if we have cash
    }
};