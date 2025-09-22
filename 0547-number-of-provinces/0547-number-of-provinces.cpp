#include <vector>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        std::vector<bool> visited(n, false); // Keep track of visited cities
        
        // Iterate through each city
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) { // If city i is not visited yet, it's a new province
                dfs(isConnected, visited, i); // DFS to mark all cities in the province as visited
                provinces++; // Increment the number of provinces
            }
        }
        
        return provinces;
    }
    
    void dfs(std::vector<std::vector<int>>& isConnected, std::vector<bool>& visited, int city) {
        visited[city] = true; // Mark the current city as visited
        
        // Iterate through the cities connected to the current city
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[city][i] && !visited[i]) { // If city i is connected to the current city and not visited
                dfs(isConnected, visited, i); // Recursively visit city i and its connections
            }
        }
    }
};