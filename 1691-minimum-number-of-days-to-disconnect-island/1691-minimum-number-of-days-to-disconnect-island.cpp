#include <vector>
using namespace std;

class Solution {
private:
    // Direction vectors for moving in 4 directions (up, down, left, right)
    vector<int> dirX = {-1, 1, 0, 0};
    vector<int> dirY = {0, 0, -1, 1};
    
    // Function to perform DFS and mark the visited land cells
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        visited[x][y] = true;
        for (int d = 0; d < 4; ++d) {
            int newX = x + dirX[d];
            int newY = y + dirY[d];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1 && !visited[newX][newY]) {
                dfs(grid, visited, newX, newY);
            }
        }
    }
    
    // Function to check the number of islands in the grid
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    if (count > 1) return count; // Early exit if more than one island
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        if (countIslands(grid) != 1) {
            return 0; // Already disconnected
        }
        
        int m = grid.size();
        int n = grid[0].size();
        
        // Try removing each land cell and check if it disconnects the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Temporarily remove this land cell
                    if (countIslands(grid) != 1) {
                        return 1; // Grid becomes disconnected after removing this cell
                    }
                    grid[i][j] = 1; // Restore the land cell
                }
            }
        }
        
        // If no single cell removal disconnects the grid, return 2
        return 2;
    }
};
