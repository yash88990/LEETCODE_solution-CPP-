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
    void preordertraversal(TreeNode *root , vector<int> &preorder){
    if(!root)return;
    //node left right
    preorder.push_back(root->val);
    preordertraversal(root->left , preorder);
    preordertraversal(root->right , preorder);
}
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preordertraversal(root , preorder);
        return preorder;
        
    }
};