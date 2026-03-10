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
    public TreeNode searchBST(TreeNode root, int val) {
        // Base case: if root is null or we found the value
        if (root == null || root.val == val) {
            return root;
        }

        // If target is smaller, search the left subtree
        if (val < root.val) {
            return searchBST(root.left, val);
        }

        // If target is larger, search the right subtree
        return searchBST(root.right, val);
    }
}