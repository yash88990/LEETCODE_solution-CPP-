/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }

        // 1. Count paths starting from the current root
        // 2. Recursively check paths starting from left and right children
        return countPaths(root, (long) targetSum) + 
               pathSum(root.left, targetSum) + 
               pathSum(root.right, targetSum);
    }

    private int countPaths(TreeNode node, long currentSum) {
        if (node == null) {
            return 0;
        }

        int count = 0;
        // Check if the current node completes a path
        if (node.val == currentSum) {
            count = 1;
        }

        // Continue searching deeper for paths that might sum to the target
        // (subtracting node.val from currentSum)
        count += countPaths(node.left, currentSum - node.val);
        count += countPaths(node.right, currentSum - node.val);

        return count;
    }
}