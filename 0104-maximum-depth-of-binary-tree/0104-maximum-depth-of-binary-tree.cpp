class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the node is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The depth of the current node is the maximum of the depths of its subtrees plus one
        return 1 + std::max(leftDepth, rightDepth);
    }
};
