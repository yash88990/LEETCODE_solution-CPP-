class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;  // Move left
            } else {
                TreeNode* node = st.top();
                // If right child exists and is not visited, move to right child
                if (node->right != nullptr && node->right != lastVisited) {
                    curr = node->right;
                } else {
                    result.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return result;
    }
};
