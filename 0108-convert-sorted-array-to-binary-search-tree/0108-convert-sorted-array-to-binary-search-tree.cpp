class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr; // Base case

        int mid = start + (end - start) / 2; // Middle element as root
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildTree(nums, start, mid - 1); // Build left subtree
        root->right = buildTree(nums, mid + 1, end);  // Build right subtree

        return root;
    }
};
