#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        const int N = 26;
        vector<vector<int>> dist(N, vector<int>(N, INF));
        
        // Initialize distance matrix with direct transformations
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        // Distance from each node to itself is 0
        for (int i = 0; i < N; ++i) {
            dist[i][i] = 0;
        }
        
        // Floyd-Warshall algorithm to find all-pairs shortest path
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Calculate the minimum cost to transform source to target
        long long totalCost = 0;
        for (int i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == INF) return -1;
            totalCost += dist[u][v];
        }
        
        return totalCost;
    }
};
