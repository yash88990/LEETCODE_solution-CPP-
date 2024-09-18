class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0 , e = nums.size() - 1 ;
        int index = -1 ;
        while(s <= e ){
            int mid = s + ( e - s ) / 2 ;
            if(nums[mid] <= target ){
                index = mid ;
                s = mid + 1 ;
            }else{
                e = mid - 1 ;
            }

            if ( index != -1  && nums[mid] == target ){
                return index ;
            }
        }
        return index + 1 ;
    }
};