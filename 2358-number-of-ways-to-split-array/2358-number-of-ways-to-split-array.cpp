class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalsum = 0;
        long long currentsum = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            totalsum += nums[i];
        }
        for(int i = 0 ; i < n - 1 ; i++){
            totalsum -= nums[i];
            currentsum += nums[i];
            if(currentsum >= totalsum) count++;
        }
        return count;
        
    }
};