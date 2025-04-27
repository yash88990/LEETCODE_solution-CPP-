class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            int start = i , mid = i+1 , end = i+2;
            if(2 * (nums[start] + nums[end]) == nums[mid])count++;
        }
        return count ;
    }
};