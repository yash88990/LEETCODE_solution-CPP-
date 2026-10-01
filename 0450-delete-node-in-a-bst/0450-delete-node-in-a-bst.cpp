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
        if(!root)return NULL;

       while(root->left)root=root->left;
       return root;
   }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        //search
        if(root->val > key){
            root->left = deleteNode(root->left , key);
        }else if(root->val < key){
            root->right = deleteNode(root->right , key);
        }else{
            //0 child
            if(!root->left && !root->right){
                delete root;
                return NULL;
            } 
            //1 child 
            else if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(!root->right && root->left){
                TreeNode* temp = root->left ;
                delete root;
                return temp;
            }
            //2 child
            else{
                TreeNode* temp = findmin(root->right);
                root->val= temp->val;
                root->right = deleteNode(root->right , temp->val);

            }
        }
        return root;
    }
};