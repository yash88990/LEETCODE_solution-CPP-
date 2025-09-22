#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, 
                                     std::vector<double>& values, 
                                     std::vector<std::vector<std::string>>& queries) {
        // Construct the graph
        std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            const std::string& A = equations[i][0];
            const std::string& B = equations[i][1];
            double value = values[i];
            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }
        
        std::vector<double> results;
        
        // Process each query
        for (const auto& query : queries) {
            const std::string& start = query[0];
            const std::string& end = query[1];
            std::unordered_set<std::string> visited;
            double result = dfs(graph, start, end, visited);
            results.push_back(result);
        }
        
        return results;
    }
    
    double dfs(std::unordered_map<std::string, std::unordered_map<std::string, double>>& graph, 
               const std::string& start, 
               const std::string& end, 
               std::unordered_set<std::string>& visited) {
        // If start or end node is not in the graph, return -1.0
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;
        
        // If start and end nodes are the same, return 1.0
        if (start == end)
            return 1.0;
        
        // Mark the start node as visited
        visited.insert(start);
        
        // Iterate through the neighbors of the start node
        for (const auto& neighbor : graph[start]) {
            const std::string& next = neighbor.first;
            // If the neighbor has not been visited, recursively search for the end node
            if (visited.find(next) == visited.end()) {
                double result = dfs(graph, next, end, visited);
                // If a valid path is found, return the product of edge weights
                if (result != -1.0)
                    return result * neighbor.second;
            }
        }
        
        // If no valid path is found, return -1.0
        return -1.0;
    }
};