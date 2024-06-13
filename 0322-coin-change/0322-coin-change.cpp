#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array with amount + 1 (a value greater than the maximum possible)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0
        
        // Update the DP table
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        
        // If dp[amount] is still amount + 1, it means we can't make that amount with the given coins
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
