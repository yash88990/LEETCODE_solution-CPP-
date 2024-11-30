#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;
        
        // Build the graph and calculate in-degrees and out-degrees
        for (const auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        // Find the start node for Eulerian path
        int start = pairs[0][0]; // Default start node
        for (const auto& [node, degree] : outDegree) {
            if (degree > inDegree[node]) {
                start = node;
                break;
            }
        }

        // Hierholzer's Algorithm to find Eulerian path
        stack<int> stk;
        vector<int> path;
        stk.push(start);
        
        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stk.push(next);
            } else {
                path.push_back(node);
                stk.pop();
            }
        }
        
        // Reverse the path to get the correct order
        reverse(path.begin(), path.end());
        
        // Construct the result from the path
        vector<vector<int>> result;
        for (size_t i = 0; i + 1 < path.size(); ++i) {
            result.push_back({path[i], path[i + 1]});
        }
        
        return result;
    }
};
