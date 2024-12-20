class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root; // Handle the edge case of an empty tree
        
        // Initialize a queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false; // Flag to check if the current level is odd
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<TreeNode*> currentLevel;
            
            // Process nodes of the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node);
                
                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Reverse the node values if the level is odd
            if (isOddLevel) {
                int left = 0, right = currentLevel.size() - 1;
                while (left < right) {
                    swap(currentLevel[left]->val, currentLevel[right]->val);
                    ++left;
                    --right;
                }
            }
            
            // Toggle the flag for odd/even levels
            isOddLevel = !isOddLevel;
        }
        
        return root;
    }
};
