class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);  // Push the root node into the queue
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);  // Create a vector for the current level

            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

                // Determine the correct index based on the direction
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;

                // Enqueue child nodes
                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);
            }

            result.push_back(ans);  // Add the current level to the result
            leftToRight = !leftToRight;  // Toggle the direction
        }

        return result;
    }
};
