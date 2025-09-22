

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0; // If the tree is empty, return 0
        
        int maxSumLevel = 1; // Initialize the level with the maximum sum
        int maxSum = root->val; // Initialize the maximum sum
        
        std::queue<TreeNode*> q;
        q.push(root); // Push the root node into the queue
        
        int level = 1; // Initialize the current level
        
        while (!q.empty()) {
            int levelSize = q.size(); // Get the number of nodes at the current level
            int levelSum = 0; // Initialize the sum of values at the current level
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val; // Add the value of the current node to the level sum
                
                // Add left and right children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Update the maximum sum and the level with the maximum sum if necessary
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxSumLevel = level;
            }
            
            ++level; // Move to the next level
        }
        
        return maxSumLevel;
    }
};