class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0] , maxsum = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if( nums[i-1] < nums[i]){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            maxsum = max(sum  , maxsum);
        }
        return maxsum;
    }
};