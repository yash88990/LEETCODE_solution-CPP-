/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is null, or is one of p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Recursively search in the left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        // If both sides return non-null, p and q are found in different subtrees
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }
        
        // Otherwise, return the non-null side
        return leftLCA != nullptr ? leftLCA : rightLCA;
    }
};