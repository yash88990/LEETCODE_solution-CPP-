class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod= nums[0];
        int minprod = nums[0];
        int result = maxprod;
        for(int i = 1 ; i < n ; i++){
            int temp_max = maxprod;
            int temp_min = minprod;
            maxprod = max(nums[i] ,  max(temp_max * nums[i], temp_min * nums[i]));
            minprod = min(nums[i] , min(temp_max * nums[i] , temp_min * nums[i]));
            result = max(result , maxprod);
        }
        return result;
    }
};