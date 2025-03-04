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
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1,
                               inorderIndex);
    }

private:
    TreeNode* buildTreeHelper(const vector<int>& inorder, int inStart, int inEnd,
                              const vector<int>& postorder, int postStart, int postEnd,
                              const unordered_map<int, int>& inorderIndex) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // The last element of postorder is the root of the tree.
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root in inorder traversal.
        int rootIndex = inorderIndex.at(rootVal);

        // Calculate the size of the left subtree.
        int leftSubtreeSize = rootIndex - inStart;

        // Recursively build the left and right subtrees.
        root->left = buildTreeHelper(inorder, inStart, rootIndex - 1,
                                     postorder, postStart, postStart + leftSubtreeSize - 1,
                                     inorderIndex);
        root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd,
                                      postorder, postStart + leftSubtreeSize, postEnd - 1,
                                      inorderIndex);

        return root;
    }
};