class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0; // Base case: empty tree

        if (!root->left) return 1 + minDepth(root->right); // No left child
        if (!root->right) return 1 + minDepth(root->left); // No right child

        return 1 + min(minDepth(root->left), minDepth(root->right)); // Both children exist
    }
};
