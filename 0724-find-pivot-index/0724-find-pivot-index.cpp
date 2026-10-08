class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0 , leftsum = 0;
        for(int n : nums)totalsum += n;
        for(int i = 0 ; i < nums.size() ; i++){
            if(totalsum - leftsum - nums[i]   == leftsum)return i;
            leftsum += nums[i];
        }
        return -1;
    }
};