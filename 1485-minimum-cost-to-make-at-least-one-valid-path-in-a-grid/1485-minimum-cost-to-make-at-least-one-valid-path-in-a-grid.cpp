#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Priority queue: (cost, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [current_cost, x, y] = pq.top();
            pq.pop();

            // If we reach the bottom-right cell
            if (x == m - 1 && y == n - 1) {
                return current_cost;
            }

            // Skip if the current path is not optimal
            if (current_cost > cost[x][y]) {
                continue;
            }

            // Explore neighbors
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first;
                int ny = y + directions[d].second;
                int new_cost = current_cost + (grid[x][y] == d + 1 ? 0 : 1);

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && new_cost < cost[nx][ny]) {
                    cost[nx][ny] = new_cost;
                    pq.emplace(new_cost, nx, ny);
                }
            }
        }

        return -1; // Should not reach here
    }
};
