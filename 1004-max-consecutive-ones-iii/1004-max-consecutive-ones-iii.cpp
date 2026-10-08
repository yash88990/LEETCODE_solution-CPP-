class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxi = 0 , cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0 )cnt++;
            while(cnt > k){
                if(nums[left] == 0)cnt--;
                left++;
            }
            maxi = max(maxi , i - left +  1);
        }
        return maxi;
    }
};