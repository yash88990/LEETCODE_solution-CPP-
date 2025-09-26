class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currentsum = 0.0;
        for(int i = 0 ; i < k ; i++){
            currentsum += nums[i];
        }
        double maxsum = currentsum;
        for(int i = k ; i < nums.size() ; i++){
            currentsum += nums[i] - nums[i-k] ;
            maxsum = max(currentsum , maxsum);
        }
        return maxsum / k;
    }
};