class Solution {
public:
    // Function to calculate depth (height) of leftmost path
    int leftDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            depth++;
            node = node->left;
        }
        return depth;
    }

    // Function to calculate depth (height) of rightmost path
    int rightDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            depth++;
            node = node->right;
        }
        return depth;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftH = leftDepth(root);
        int rightH = rightDepth(root);

        // If left and right heights are same, it's a perfect tree
        if (leftH == rightH) {
            return (1 << leftH) - 1;  // 2^h - 1 nodes in a perfect tree
        }

        // Otherwise, count nodes recursively in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
