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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        int maxsumlevel = 1;
        int maxsum = root->val;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1 ;
        while(!q.empty()){
            int n = q.size();
            int levelsum= 0;
            for(int i = 0 ; i < n ; i++){
                TreeNode* curr = q.front();
                q.pop();
                levelsum += curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(maxsum < levelsum){
                maxsum = levelsum ;
                maxsumlevel = level;
            }
            level++;
        }
        return maxsumlevel;
    }
};