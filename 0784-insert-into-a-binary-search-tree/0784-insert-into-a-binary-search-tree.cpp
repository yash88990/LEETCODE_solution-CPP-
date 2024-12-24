class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val); // Create a new node if root is null
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val); // Insert in left subtree
        } else {
            root->right = insertIntoBST(root->right, val); // Insert in right subtree
        }

        return root; // Return the root after insertion
    }
};
