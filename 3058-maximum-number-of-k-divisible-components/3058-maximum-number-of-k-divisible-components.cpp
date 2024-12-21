class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        int components = 0;
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long sum = values[node]; // Use long long to avoid overflow
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                sum += dfs(neighbor, node);
            }
            if (sum % k == 0) {
                components++;
                return 0LL; // Reset the sum since this component can be split
            }
            return sum; // Otherwise, propagate the sum upwards
        };
        
        dfs(0, -1);
        return components;
    }
};
