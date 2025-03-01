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
    void postordertraversal(TreeNode *root , vector<int> &postorder){
    if(!root)return;
    //left right node
    postordertraversal(root->left , postorder);
    postordertraversal(root->right , postorder);
    postorder.push_back(root->val);
    
}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postordertraversal(root , postorder);
        return postorder;
    }
};