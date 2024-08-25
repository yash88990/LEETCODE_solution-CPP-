class Solution {
public:
    vector<int> result;  // Vector to store the result

    void postorder(TreeNode* node) {
        if (node == nullptr) return;

        // First recur on the left subtree
        postorder(node->left);

        // Then recur on the right subtree
        postorder(node->right);

        // Finally, visit the root node
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);  // Start the recursive traversal
        return result;
    }
};
