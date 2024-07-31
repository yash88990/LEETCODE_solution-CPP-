#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] means the minimum height for placing first i books
        dp[0] = 0; // No books, no height

        for (int i = 1; i <= n; ++i) {
            int width = 0, height = 0;
            // Try to place the i-th book on the current shelf
            for (int j = i; j > 0; --j) {
                width += books[j-1][0];
                if (width > shelfWidth) break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }

        return dp[n];
    }
};
