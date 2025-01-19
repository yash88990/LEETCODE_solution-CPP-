#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0;

        // Priority queue to store cells by height
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add boundary cells to the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int waterTrapped = 0;

        // Process the priority queue
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();

            int x = cell.first, y = cell.second;

            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    // Water trapped at this cell
                    waterTrapped += max(0, height - heightMap[nx][ny]);

                    // Update height and push to the queue
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped;
    }
};
