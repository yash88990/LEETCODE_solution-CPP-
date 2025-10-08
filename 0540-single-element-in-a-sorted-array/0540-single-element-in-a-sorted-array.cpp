class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        int l = 0 , r = n-1 ;
        while(l < r ){
            int mid = l + (r-l) / 2 ;
            if(mid % 2 == 1 ){
                mid-- ;
            }
            if(nums[mid] != nums[mid+1]){
                r = mid ;
            }else{
                l = mid + 2 ;
            }
        }
        return nums[l] ;
    }
};