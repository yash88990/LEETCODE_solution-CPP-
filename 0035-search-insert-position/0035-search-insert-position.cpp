class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0 , e = nums.size() - 1 , ans = -1;
        while(s <= e ){
            int m = s + ( e - s )/ 2;
            if(nums[m] == target)return m;
            else if(nums[m] < target){
                ans = m;
                s = m + 1 ;
            }else e =m-1;
        }
        return ans +  1;
    }
};