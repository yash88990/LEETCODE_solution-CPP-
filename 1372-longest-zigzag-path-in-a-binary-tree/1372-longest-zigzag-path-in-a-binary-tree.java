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
    int maxPath = 0;

    public int longestZigZag(TreeNode root) {
        // Start DFS from root in both directions
        // true = left, false = right
        dfs(root.left, true, 1);
        dfs(root.right, false, 1);
        return maxPath;
    }

    private void dfs(TreeNode node, boolean isLeft, int length) {
        if (node == null) return;

        maxPath = Math.max(maxPath, length);

        if (isLeft) {
            // If we came from left, to continue zigzag, we must go right
            dfs(node.right, false, length + 1);
            // Or start a new zigzag by going left again
            dfs(node.left, true, 1);
        } else {
            // If we came from right, to continue zigzag, we must go left
            dfs(node.left, true, length + 1);
            // Or start a new zigzag by going right again
            dfs(node.right, false, 1);
        }
    }
}