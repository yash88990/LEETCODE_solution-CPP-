class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       if (root == nullptr) return {};
        
        stack<TreeNode*> s1, s2;
        vector<int> result;
        
        s1.push(root);
        
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        
        return result;
    }
};
