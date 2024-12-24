class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root; // Base case: Found the node or reached the end
        }

        if (val < root->val) {
            return searchBST(root->left, val); // Search in left subtree
        } else {
            return searchBST(root->right, val); // Search in right subtree
        }
    }
};
