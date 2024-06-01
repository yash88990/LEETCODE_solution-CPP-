class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting or ending point is an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        // Create a 2D dp array initialized to 0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the starting position
        dp[0][0] = 1;
        
        // Fill the dp array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the current cell is an obstacle, continue
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    // If not on the first row, add the value from the top cell
                    if (i > 0) {
                        dp[i][j] += dp[i-1][j];
                    }
                    // If not on the first column, add the value from the left cell
                    if (j > 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        
        // Return the value in the bottom-right corner
        return dp[m-1][n-1];
    }
};
