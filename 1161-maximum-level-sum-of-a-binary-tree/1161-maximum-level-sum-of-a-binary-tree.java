import java.util.LinkedList;
import java.util.Queue;

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
    public int maxLevelSum(TreeNode root) {
        if (root == null) return 0;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        int max_sum = Integer.MIN_VALUE;
        int max_level = 1;
        int current_level = 1;

        while (!q.isEmpty()) {
            int n = q.size();
            long sum = 0; // Using long to prevent overflow during addition

            // Process all nodes at the current level
            for (int i = 0; i < n; i++) {
                TreeNode temp = q.poll();
                sum += temp.val;

                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
            }

            // Update max_sum and track the level index
            if (sum > max_sum) {
                max_sum = (int) sum;
                max_level = current_level;
            }
            current_level++;
        }

        return max_level;
    }
}