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
    private int count = 0;

    public int goodNodes(TreeNode root) {
        // Start DFS with the root's value as the initial maximum
        dfs(root, root.val);
        return count;
    }

    private void dfs(TreeNode node, int maxSoFar) {
        if (node == null) {
            return;
        }

        // If current node's value is >= maximum seen on this path, it's a "good" node
        if (node.val >= maxSoFar) {
            count++;
            maxSoFar = node.val; // Update the path's maximum
        }

        // Explore children with the updated maximum
        dfs(node.left, maxSoFar);
        dfs(node.right, maxSoFar);
    }
}