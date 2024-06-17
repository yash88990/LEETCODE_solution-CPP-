#include <iostream>
using namespace std;



class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr, *pred = nullptr;
        
        while (root) {
            if (root->left) {
                // Find the rightmost node in the left subtree or the inorder predecessor
                pred = root->left;
                while (pred->right && pred->right != root) {
                    pred = pred->right;
                }
                // Link the predecessor to root
                if (!pred->right) {
                    pred->right = root;
                    root = root->left;
                } else {
                    // Revert the changes and fix the swapped nodes
                    if (prev && root->val < prev->val) {
                        if (!first) first = prev;
                        second = root;
                    }
                    prev = root;

                    pred->right = nullptr;
                    root = root->right;
                }
            } else {
                if (prev && root->val < prev->val) {
                    if (!first) first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            }
        }
        // Swap the values of the two nodes
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};
