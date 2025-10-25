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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(!s.empty() || curr){
            //left jana h
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            //store krlo
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            //right me jao
            curr = curr->right;
        }
        return ans;
    }
};