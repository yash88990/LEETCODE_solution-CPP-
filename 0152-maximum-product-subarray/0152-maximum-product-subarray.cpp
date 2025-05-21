class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
    
    int max_product = nums[0];
    int min_product = nums[0];
    int result = max_product;

    for (int i = 1; i < nums.size(); ++i) {
        int temp_max = max_product;
        int temp_min = min_product;
        max_product = max(nums[i], max(temp_max * nums[i], temp_min * nums[i]));
        min_product = min(nums[i], min(temp_max * nums[i], temp_min * nums[i]));
        result = max(result, max_product);
    }
    
    return result;
    }
};