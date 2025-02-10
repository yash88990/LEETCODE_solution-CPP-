class Solution {
public:
    vector<TreeNode*> nodes;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        TreeNode *first = nullptr, *second = nullptr;
        
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                if (!first) first = nodes[i];  // First violation
                second = nodes[i + 1];  // Second violation
            }
        }
        swap(first->val, second->val);  // Swap to fix the BST
    }
};
