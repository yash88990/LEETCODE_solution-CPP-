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
    int solve(TreeNode* root , int currentSum){
        //base case 
        if(root == NULL ) return 0;
        currentSum  = currentSum * 10 + root->val;
        if(root->left == NULL && root->right == NULL)  {
            return currentSum;
        }
        return solve(root->left , currentSum) + solve(root->right , currentSum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root , 0);
    }
};