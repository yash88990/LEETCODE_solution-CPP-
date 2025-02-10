class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        
        return false;
    }
};
