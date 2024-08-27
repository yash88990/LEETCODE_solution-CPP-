#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Build the graph as an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        // Probability array to store the maximum probability to reach each node
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;  // Start node has a probability of 1 to itself

        // Max-heap priority queue to process nodes
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});  // Start with the start node

        // Dijkstra-like algorithm to maximize probability
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If we reach the end node, return the current probability
            if (node == end) {
                return currProb;
            }

            // Process all neighbors
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                // If we find a higher probability path to nextNode, update it
                if (prob[nextNode] < currProb * edgeProb) {
                    prob[nextNode] = currProb * edgeProb;
                    pq.push({prob[nextNode], nextNode});
                }
            }
        }

        // If we finish processing without reaching the end node, return 0
        return 0.0;
    }
};
