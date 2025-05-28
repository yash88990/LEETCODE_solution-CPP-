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
    void preorder(TreeNode* root , vector<int>&result){
        //base case
        if(root == NULL)return ;
        //node left right
        //1. node (insert in ans)
        result.push_back(root->val);
        //2. go to the left side
        preorder(root->left , result);
        //3. go to the right side
        preorder(root->right , result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        preorder(root , result);
        return result;
    }
};