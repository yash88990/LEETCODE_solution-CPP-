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
    int dfs(TreeNode* root, int targetSum, unordered_map<long long,int> &prefixsum  , long long currsum){
        if(!root)return 0;
        currsum += root->val;
        int cnt = prefixsum[currsum - targetSum];
         prefixsum[currsum]++;
        cnt += dfs(root->left , targetSum , prefixsum , currsum);
        cnt += dfs(root->right , targetSum , prefixsum , currsum);
        prefixsum[currsum]--;
        return cnt;

    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>prefixsum;
        prefixsum[0]=1;
        return dfs(root , targetSum , prefixsum , 0);
    }
};