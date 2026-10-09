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
    int maxi = 0;
    void dfs(TreeNode* root , bool cangoleft , int length){
        if(!root)return ;
        maxi = max(maxi , length);
        if(cangoleft){
            dfs(root->right , false, length + 1 );
            dfs(root->left , true, 1);
        }else{
            dfs(root->left , true , length + 1 );
            dfs(root->right , false , 1);

        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
        dfs(root->left , true , 1); 
        dfs(root->right , false , 1);
      
        return maxi;
    }
};