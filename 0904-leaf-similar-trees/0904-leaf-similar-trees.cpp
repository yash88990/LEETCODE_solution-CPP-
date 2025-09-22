class Solution {
public:
    // Helper function to perform DFS and collect leaf values
    void dfs(TreeNode* node, vector<int>& leaves) {
        if (!node) return;  // If the node is null, return
        if (!node->left && !node->right) {  // If the node is a leaf
            leaves.push_back(node->val);  // Add its value to the list
        }
        // Recur for left and right subtrees
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        dfs(root1, leaves1);  // Collect leaves of the first tree
        dfs(root2, leaves2);  // Collect leaves of the second tree
        return leaves1 == leaves2;  // Compare the two leaf sequences
    }
};