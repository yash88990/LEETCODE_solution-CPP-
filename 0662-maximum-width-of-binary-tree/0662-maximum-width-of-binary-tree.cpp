#include <queue>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;  // Use long long for index
        q.push({root, 0}); // Root starts with index 0

        while (!q.empty()) {
            int size = q.size();
            long long leftMostIndex = q.front().second; // Normalize indices
            long long first = 0, last = 0;
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                // Normalize index by subtracting leftMostIndex to avoid overflow
                index -= leftMostIndex;

                if (i == 0) first = index;  // First node in level
                if (i == size - 1) last = index;  // Last node in level
                
                // Push children with updated indices
                if (node->left) q.push({node->left, 2 * index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }
            
            maxWidth = max(maxWidth, static_cast<int>(last - first + 1));
        }

        return maxWidth;
    }
};
