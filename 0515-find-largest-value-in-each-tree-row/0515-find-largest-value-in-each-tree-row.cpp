
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Update max value for the current level
                maxVal = max(maxVal, node->val);

                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Store the maximum value of the current level
            result.push_back(maxVal);
        }

        return result;
    }
};
