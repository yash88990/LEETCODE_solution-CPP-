class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark guards and walls on the grid
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1; // Guard
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2; // Wall
        }

        // Directions: north, south, east, west
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // Mark cells visible to guards
        for (const auto& guard : guards) {
            for (const auto& dir : directions) {
                int x = guard[0];
                int y = guard[1];
                while (true) {
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 1 || grid[x][y] == 2) {
                        break; // Stop at walls, guards, or boundaries
                    }
                    if (grid[x][y] == 0) {
                        grid[x][y] = 3; // Mark as guarded
                    }
                }
            }
        }

        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { // Empty and unguarded cell
                    unguarded++;
                }
            }
        }

        return unguarded;
    }
};