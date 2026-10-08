class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n = nums.size();
       int left = 0 , right = 0 , cnt = 0 , maxi = 0;
       while(right < n){
        if(nums[right] == 0)cnt++;
        while(cnt > 1){
            if(nums[left] == 0 )cnt--;
            left++;
        }
        maxi = max(maxi , right - left);
        right++;
       }
       return maxi;
    }
};