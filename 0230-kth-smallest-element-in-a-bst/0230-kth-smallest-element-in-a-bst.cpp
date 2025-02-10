/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;  // Reset the counter
        result = -1;  // Reset the result
        inOrder(root, k);  // Start in-order traversal from root
        return result;
    }

private:
    int count;  // Counter to track the number of nodes visited
    int result;  // Variable to store the kth smallest value

    void inOrder(TreeNode* node, int k) {
        if (node == nullptr) return;
        inOrder(node->left, k);  // Visit left subtree
        count++;  // Visit this node
        if (count == k) {
            result = node->val;
            return;
        }
        inOrder(node->right, k);  // Visit right subtree
    }
};
