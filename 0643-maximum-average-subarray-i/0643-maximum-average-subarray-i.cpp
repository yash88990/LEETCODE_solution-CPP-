class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        int n = nums.size();
        
        for(int i = 0 ; i < k ; i++)sum += nums[i];
        double maxi = sum;
        for(int i = k ; i < n; i++){
            sum = sum +  nums[i] - nums[i-k];
            maxi = max(sum , maxi);
            
        }
        return maxi / k;
    }
};