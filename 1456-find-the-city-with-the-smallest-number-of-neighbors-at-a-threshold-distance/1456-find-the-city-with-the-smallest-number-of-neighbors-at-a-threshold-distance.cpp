#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix with large values
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Distance to itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Fill initial distances from edges
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }

        // Floyd-Warshall algorithm to compute shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the threshold
        int minReachableCities = n;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
