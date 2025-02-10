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
    
private:
    int count;  
    int result ; 
     void inOrder(TreeNode* node, int k) {
        if (node == nullptr) return;
        inOrder(node->left, k);  // Visit left subtree
        count++;  // Visit this node
        if (count == k) {
            result = node->val;
            return;
        }
        inOrder(node->right, k);  // Visit right subtree
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;  
        result = -1; 
        inOrder(root, k);  
        return result;
    }

};