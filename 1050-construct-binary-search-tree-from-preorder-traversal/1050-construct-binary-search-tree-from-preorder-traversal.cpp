class Solution {
public:
    int index = 0;  // Global index to track position in preorder array

    TreeNode* buildBST(vector<int>& preorder, int bound) {
        if (index >= preorder.size() || preorder[index] > bound)
            return NULL;  // Stop if value is out of bounds

        TreeNode* root = new TreeNode(preorder[index++]);  // Create node

        root->left = buildBST(preorder, root->val);  // Build left subtree
        root->right = buildBST(preorder, bound);  // Build right subtree

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MAX);
    }
};
