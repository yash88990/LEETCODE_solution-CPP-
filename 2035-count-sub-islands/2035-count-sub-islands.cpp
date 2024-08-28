class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &isSubIsland) {
        // Boundary check and water check
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0) {
            return;
        }
        
        // If grid2 has land, but grid1 does not have land at this position, then it's not a sub-island
        if (grid1[i][j] == 0) {
            isSubIsland = false;
        }
        
        // Mark the current cell as visited in grid2
        grid2[i][j] = 0;
        
        // Explore 4-directionally
        dfs(grid1, grid2, i + 1, j, isSubIsland);
        dfs(grid1, grid2, i - 1, j, isSubIsland);
        dfs(grid1, grid2, i, j + 1, isSubIsland);
        dfs(grid1, grid2, i, j - 1, isSubIsland);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        int subIslandCount = 0;
        
        // Traverse the grid2 to find islands
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) { // Found a new island in grid2
                    bool isSubIsland = true;
                    dfs(grid1, grid2, i, j, isSubIsland);
                    if (isSubIsland) {
                        ++subIslandCount;
                    }
                }
            }
        }
        
        return subIslandCount;
    }
};
