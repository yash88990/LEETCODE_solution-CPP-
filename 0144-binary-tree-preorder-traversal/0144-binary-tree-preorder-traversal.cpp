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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*>stk;
        if(!root)return result;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* curr = stk.top(); stk.pop();
            result.push_back(curr->val);
            if(curr->right)stk.push(curr->right);
            if(curr->left)stk.push(curr->left);
        }
        return result;
    }
};