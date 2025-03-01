class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map: {column -> {row -> multiset of values (sorted automatically)}}
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // (node, (column, row))
        
        q.push({root, {0, 0}}); // Start with root at (0,0)
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int x = pos.first, y = pos.second;
            
            nodes[x][y].insert(node->val); // Insert the node into the map
            
            if (node->left) 
                q.push({node->left, {x - 1, y + 1}});
            if (node->right) 
                q.push({node->right, {x + 1, y + 1}});
        }
        
        vector<vector<int>> result;
        
        // Iterate through columns
        for (auto& [col, rowMap] : nodes) {
            vector<int> colVals;
            // Iterate through rows in the column
            for (auto& [row, values] : rowMap) {
                colVals.insert(colVals.end(), values.begin(), values.end());
            }
            result.push_back(colVals);
        }
        
        return result;
    }
};
