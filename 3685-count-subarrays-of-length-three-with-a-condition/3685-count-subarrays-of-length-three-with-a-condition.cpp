class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            int start = nums[i], mid = nums[i+1] , end = nums[i+2];
            if(2 * ( start + end) == mid)count++;
        }
        return count ;
        
    }
};