class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first element that is not in ascending order from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If no such element is found, reverse the entire array and return
        if (i < 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 2: Find the smallest element to the right of i that is greater than nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        
        // Step 3: Swap nums[i] and nums[j]
        std::swap(nums[i], nums[j]);
        
        // Step 4: Reverse the sub-array to the right of i
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};