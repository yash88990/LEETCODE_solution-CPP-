class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);  // Start DFS with the smallest possible integer value
    }
    
private:
    // DFS helper function to count good nodes
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;  // If the node is null, return 0
        
        // Check if the current node is a good node
        int good = node->val >= maxVal ? 1 : 0;
        
        // Update the maximum value seen so far
        maxVal = std::max(maxVal, node->val);
        
        // Continue DFS on the left and right children
        good += dfs(node->left, maxVal);
        good += dfs(node->right, maxVal);
        
        return good;  // Return the total count of good nodes
    }
};