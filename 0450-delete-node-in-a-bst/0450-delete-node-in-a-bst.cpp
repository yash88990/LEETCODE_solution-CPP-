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
    TreeNode* findmin(TreeNode* root){
    while(root->left)root = root->left;
    return root;
}


    TreeNode* deleteNode(TreeNode* root, int val) {
        if(!root)return root;
    //searching
    if(val < root->val){
        root->left = deleteNode(root->left , val);
        
    }else if(val  > root->val){
        root->right = deleteNode(root->right , val);
    }else{
        //mil gaya 
        //check for their child
        //only one child
        if(!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if(!root->right){
            TreeNode* temp = root->left ;
            delete root ;
            return temp;
        }else{
            //have 2 child
            TreeNode* temp = findmin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right ,temp->val );
            
        }
    }
    return root;
    }
};