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
    void inorder(TreeNode* root , vector<int>&ans){
        if(!root)return ;
        //left
        inorder(root->left , ans);
        //node
        if(!root->left && !root->right)ans.push_back(root->val);
        //right
        inorder(root->right , ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2)return false;
        vector<int> leaf1 , leaf2;
        inorder(root1 , leaf1);
        inorder(root2 , leaf2);
        if(leaf1.size() != leaf2.size())return false;
        for(int i= 0 ; i < leaf1.size() ; i++){
            if(leaf1[i] != leaf2[i])return false;
        }
        return true;
    }
};