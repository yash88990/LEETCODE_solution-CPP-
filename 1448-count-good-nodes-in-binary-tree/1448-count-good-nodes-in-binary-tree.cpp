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
    int dfs(TreeNode* root , int maxi){
        if(!root)return 0;
        int good = root->val >= maxi ? 1 : 0;
        maxi = max(maxi , root->val);
        good += dfs(root->left , maxi);
        good += dfs(root->right , maxi);
        return good;
    } 
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        return dfs(root , INT_MIN);
    }
};











