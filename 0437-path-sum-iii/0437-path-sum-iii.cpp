
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // Initialize with sum 0 to account for paths from the root
        return dfs(root, 0, targetSum, prefixSumCount);
    }
    
private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (node == nullptr) {
            return 0;
        }
        
        currentSum += node->val;
        int pathCount = prefixSumCount[currentSum - targetSum]; // Check if there is a prefix sum that makes up the target sum
        
        prefixSumCount[currentSum]++; // Update the prefix sum count for the current path
        
        // Recur for left and right subtrees
        pathCount += dfs(node->left, currentSum, targetSum, prefixSumCount);
        pathCount += dfs(node->right, currentSum, targetSum, prefixSumCount);
        
        prefixSumCount[currentSum]--; // Remove the current sum from the map to backtrack
        
        return pathCount;
    }
};