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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;

        if (key < root.val) {
            // Target is in the left subtree
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            // Target is in the right subtree
            root.right = deleteNode(root.right, key);
        } else {
            // Node to delete found!
            
            // Case 1 & 2: Leaf or one child
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;

            // Case 3: Two children
            // Find the inorder successor (smallest in the right subtree)
            TreeNode successor = findMin(root.right);
            root.val = successor.val;
            // Delete the inorder successor
            root.right = deleteNode(root.right, successor.val);
        }
        return root;
    }

    private TreeNode findMin(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
}