class Solution {
int  firstocc(vector<int>& nums, int target){
        int s = 0 , e = nums.size() - 1 ;
        int ans = -1 ;
        while ( s <= e ){
            int m = s + ( e - s ) / 2 ;
            if(nums[m] == target ){
                ans = m ;
                e = m - 1 ;
            }else if ( nums[m] > target ){
                e = m - 1 ;
            }else{
                s = m + 1 ;
            }
            m = s + ( e - s ) / 2 ;
        }
        return ans ;
    }
int  lastocc(vector<int>& nums, int target){
        int s = 0 , e = nums.size() - 1 ;
        int ans = -1 ;
        while ( s <= e ){
            int m = s + ( e - s ) / 2 ;
            if(nums[m] == target ){
                ans = m ;
                s  = m + 1 ;
            }else if ( nums[m] > target ){
                e = m - 1 ;
            }else{
                s = m + 1 ;
            }
            m = s + ( e - s ) / 2 ;
        }
        return ans ;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> p(2);
        p[0] = firstocc(nums, target);
        p[1] = lastocc(nums, target);
        return p;
    }
};