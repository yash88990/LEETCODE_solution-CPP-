#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build the graph as an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        // Max heap (priority queue) to perform a modified Dijkstra's algorithm
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);  // Start with the start node with probability 1

        // Vector to store the max probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        // Dijkstra-like algorithm to find max probability path
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If we reach the end node, return the result
            if (node == end_node) {
                return prob;
            }

            // Explore neighbors
            for (auto& neighbor : graph[node]) {
                int next_node = neighbor.first;
                double edge_prob = neighbor.second;
                double new_prob = prob * edge_prob;

                // If we find a higher probability path to the next node, update it
                if (new_prob > maxProb[next_node]) {
                    maxProb[next_node] = new_prob;
                    pq.emplace(new_prob, next_node);
                }
            }
        }

        // If we cannot reach the end node, return 0
        return 0.0;
    }
};
