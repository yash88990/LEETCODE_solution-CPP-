
class Solution {
public:
    int maxLength = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;

        maxLength = std::max(maxLength, length);
        
        if (isLeft) {
            // If we came from the left, go to the right
            dfs(node->right, false, length + 1);
            // Start a new path from the left child
            dfs(node->left, true, 1);
        } else {
            // If we came from the right, go to the left
            dfs(node->left, true, length + 1);
            // Start a new path from the right child
            dfs(node->right, false, 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0); // Start assuming the previous move was to the left
        dfs(root, false, 0); // Start assuming the previous move was to the right
        return maxLength;
    }
};