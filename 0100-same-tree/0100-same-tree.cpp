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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q)return false;
        if(p && !q)return false;
        if(!p && !q)return true;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right , q->right);
        bool data = (p->val == q->val);
        if(left  && right && data)return true;
        else return false;

    }
};