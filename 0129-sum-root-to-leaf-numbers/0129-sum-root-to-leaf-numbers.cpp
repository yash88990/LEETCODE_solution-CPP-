class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0; // Base case: null node
        
        currentSum = currentSum * 10 + node->val; // Update the number
        
        // If leaf node, return the current sum
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Recur for left and right children
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
