class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0] , currsum = 0;
        for(int num : nums){
            currsum = max(num , currsum + num);
            maxsum = max(maxsum , currsum);
        }
        return maxsum;
    }
};