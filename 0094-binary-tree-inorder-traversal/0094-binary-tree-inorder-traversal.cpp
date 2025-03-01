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
    void inordertraveral(TreeNode *root , vector<int> &inorder){
    if(!root)return;
    //left node right
    inordertraveral(root->left , inorder);
    inorder.push_back(root->val);
    inordertraveral(root->right , inorder);

}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inordertraveral(root , inorder);
        return inorder;
    }
};