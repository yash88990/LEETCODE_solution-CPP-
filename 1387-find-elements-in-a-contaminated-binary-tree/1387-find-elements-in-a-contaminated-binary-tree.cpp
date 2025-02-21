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
class FindElements {
    unordered_set<int> set;
    void recoverbinarytree(TreeNode* curr , int val){
        if(!curr) return;
        set.insert(val);
        recoverbinarytree(curr->left , 2 * val + 1 );
        recoverbinarytree(curr->right , 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        set.insert(0); 
        recoverbinarytree(root->left , 1 );
        recoverbinarytree(root->right,2);
    }
    
    bool find(int target) {
        return set.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */