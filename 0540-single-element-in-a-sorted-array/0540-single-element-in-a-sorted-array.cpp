class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0 , e = nums.size()-1;
        while( s < e ){
            int m = s + ( e - s )/2;
            if(m % 2 == 1)m--;
            if(nums[m] != nums[m + 1 ])e = m;
            else s = m + 2 ;
        }
        return nums[e];
    }
};