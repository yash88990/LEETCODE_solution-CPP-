class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        int sum =0;
        for(int i = 0 ;i < n  ; i++){
            sum = max(sum + nums[i] , nums[i]);
            maxsum = max(sum , maxsum);
        }

        return maxsum;
    }
};