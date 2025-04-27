class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i < nums.size() -2 ; i++){
            int start = i , end = i + 2;
            if(2 * (nums[start] + nums[end]) == nums[start + 1]  )count++;
        }
        return count;
    }
};