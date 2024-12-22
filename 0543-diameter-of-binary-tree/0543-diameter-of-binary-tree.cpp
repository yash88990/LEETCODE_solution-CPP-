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
pair<int , int>  solve(TreeNode* root){
     if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
     }
     pair<int,int> left = solve(root->left);
     pair<int,int> right = solve(root->right);

        int ans1 = left.first;
        int ans2 = right.first;
        int ans3 = left.second + right.second ;
       pair<int,int> finalans;
       finalans.first = max(ans1 , max(ans2 , ans3));
       finalans.second = max(left.second , right.second) + 1 ;
       return finalans;
}
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
       
    }
};