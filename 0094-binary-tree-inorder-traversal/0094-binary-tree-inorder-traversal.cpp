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
    void inorder(TreeNode* root , vector<int> &result){
        //base case 
        if(root == NULL)return;
        // left node right
        //1.go to the left side first
        inorder(root->left , result);
        //2. insert the node (root element) in ans
        result.push_back(root->val);
        //3. got to the right side 
        inorder(root->right , result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root , result);
        return result;

    }
};