class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int inc = 1 , desc = 1 , ans = 1 ;
        for(int i = 1 ; i < n ; i++){
            if(nums[i-1] < nums[i]){
                inc++;
                desc=1;
            }else if(nums[i-1] > nums[i]){
                desc++;
                inc = 1 ;
            }else{
                inc = 1 ;
                desc = 1;
            }
            ans = max(ans , max(inc , desc));
        }
        return ans;
    }
};