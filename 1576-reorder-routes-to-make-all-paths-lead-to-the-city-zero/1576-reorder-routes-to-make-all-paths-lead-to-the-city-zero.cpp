#include <vector>
#include <unordered_map>

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        // Create an adjacency list to represent the tree
        std::unordered_map<int, std::vector<std::pair<int, bool>>> adjList;
        
        // Populate the adjacency list
        for (const auto& connection : connections) {
            int from = connection[0];
            int to = connection[1];
            // Add forward edge from 'from' to 'to' and mark it as needing reversal
            adjList[from].emplace_back(to, true);
            // Add backward edge from 'to' to 'from' without marking it for reversal
            adjList[to].emplace_back(from, false);
        }
        
        int minChanges = 0;
        std::vector<bool> visited(n, false); // Keep track of visited cities
        
        // Perform DFS starting from city 0
        dfs(adjList, visited, 0, minChanges);
        
        return minChanges;
    }
    
    void dfs(std::unordered_map<int, std::vector<std::pair<int, bool>>>& adjList, 
             std::vector<bool>& visited, int city, int& minChanges) {
        visited[city] = true; // Mark the current city as visited
        
        // Traverse through the adjacent cities
        for (const auto& neighbor : adjList[city]) {
            int nextCity = neighbor.first;
            bool forwardEdge = neighbor.second;
            
            if (!visited[nextCity]) {
                // If the edge is in the forward direction, increment minChanges
                if (forwardEdge)
                    minChanges++;
                dfs(adjList, visited, nextCity, minChanges); // Recursively visit the neighbor
            }
        }
    }
};