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
void preorder(TreeNode* root , vector<int>& result){ //  root  left right
    //base case 
    if(root == NULL) return;
    result.push_back(root->val);  // root 
    preorder(root->left , result);  // left 
    preorder(root->right , result);  // right
     
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root , result);
        return result;
    }
};