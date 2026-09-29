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
    int height(TreeNode* root){
        if(!root)return 0;
        int l = height(root->left);
        int r = height(root->right);
        int ans = max(l , r)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        if(left && right && diff)return true;
        return false;

    }
};