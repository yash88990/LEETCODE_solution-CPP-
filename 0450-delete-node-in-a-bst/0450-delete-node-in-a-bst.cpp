/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode* findMin(TreeNode* node) {
    while (node->left) node = node->left;
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL; // Base case: Empty tree

    if (key < root->val) {
        root->left = deleteNode(root->left, key);  // Move left
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key); // Move right
    } else { 
        // Found the node to delete
        if (!root->left) return root->right;  // No left child
        if (!root->right) return root->left;  // No right child

        // Two children: Find inorder successor (smallest in right subtree)
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;  // Copy successor value
        root->right = deleteNode(root->right, temp->val);  // Delete successor node
    }
    
    return root;
}

};