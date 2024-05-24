class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() ;
        int l = 0 , r = n-1 , index = -1 ;
        while (l <= r ){
            int mid = l + ( r - l ) / 2 ;
            if ( nums[mid] <= target ){
                index = mid ;
                l = mid + 1 ;
            }else{
                r = mid - 1 ;
            }
        }
        if ( index != -1 && nums[index ] == target ){
            return index ;
        }
        return index + 1 ;
    }
};