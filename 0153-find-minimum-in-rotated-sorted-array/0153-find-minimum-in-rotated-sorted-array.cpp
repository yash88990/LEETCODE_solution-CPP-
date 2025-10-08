class Solution {
public:
    int findMin(vector<int>& nums) {
        int  s = 0 , e = nums.size()-1;
        while(s < e ){
            int m = s + (e -  s)/2;
            if(nums[s] <= nums[m])s = m  ;
            else e = m -1 ;
        }
        return nums[s];
    }
};