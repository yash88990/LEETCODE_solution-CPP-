// #include <unordered_map>
// #include <vector>
// using namespace std;

// // Binary Tree Node ka definition
// struct TreeNode {
//     int val; // Node ka value
//     TreeNode* left; // Left child pointer
//     TreeNode* right; // Right child pointer
//     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} // Constructor with left and right pointers
// };

class Solution {
public:
    // Helper function jo binary tree banata hai
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                              vector<int>& inorder, int inStart, int inEnd, 
                              unordered_map<int, int>& inMap) {
        // Agar range invalid ho, to NULL return karo
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // Preorder ka first element root hota hai
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal); // Naya node banao

        // Root ka index inorder array me dhoondo
        int inRoot = inMap[rootVal];
        int numsLeft = inRoot - inStart; // Left subtree ke nodes ki sankhya

        // Left subtree ke liye recursion karo
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, 
                                     inorder, inStart, inRoot - 1, inMap);

        // Right subtree ke liye recursion karo
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, 
                                      inorder, inRoot + 1, inEnd, inMap);

        return root; // Root node ko return karo
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Inorder array ke elements ke indices ko hashmap me store karo
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Helper function ko call karo poore range ke saath
        return buildTreeHelper(preorder, 0, preorder.size() - 1, 
                               inorder, 0, inorder.size() - 1, inMap);
    }
};
