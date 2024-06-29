#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Adjacency list representation of the graph
        vector<vector<int>> graph(n);
        // In-degree array to help with topological sorting
        vector<int> inDegree(n, 0);

        // Building the graph and the in-degree array
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Queue for topological sorting
        queue<int> q;
        // Initialize queue with all nodes having in-degree 0
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // List of sets to keep track of ancestors for each node
        vector<set<int>> ancestors(n);

        // Perform topological sort and update ancestors
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Traverse all children of the current node
            for (int child : graph[node]) {
                // Insert the current node's ancestors into the child's ancestor set
                ancestors[child].insert(node);
                ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());

                // Decrease in-degree and add to queue if it becomes 0
                if (--inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        // Prepare the result in the required format (sorted lists)
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};
