class Solution {
public:
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        if (root == nullptr) return true; // Empty tree is a valid BST

        if (root->val <= minVal || root->val >= maxVal) return false; // Check BST condition

        // Recursively validate left and right subtrees
        return isValidBST(root->left, minVal, root->val) && 
               isValidBST(root->right, root->val, maxVal);
    }
};
