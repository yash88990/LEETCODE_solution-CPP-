class Solution {
    int firstocc(vector<int>& nums, int target ){
        int s = 0 , e = nums.size() - 1 ;
        int ans = -1 ;
        while( s <= e ){
            int mid = s + ( e - s ) /  2;
            if ( nums[mid] == target ) {
                ans = mid ;
                // first occ ke lliye left part me jana hai 
            e = mid - 1 ;
            }else if ( nums[mid] > target ){
                e = mid - 1 ;
            }else{ // nums[mid] < target 
            s = mid + 1 ;

            }
            mid = s + ( e - s ) / 2 ;
        }
        return ans ;
    }

int lastocc(vector<int>& nums, int target){
    int s = 0 , e = nums.size() -  1;
    int ans = -1 ;
    while ( s <= e ){
        int mid = s + ( e - s ) / 2 ;
        if ( nums[mid] == target ) {
            ans = mid ;
            // last occ ke liye right me jana h 
            s = mid + 1 ;
        }else if ( nums[mid] > target ){
            e = mid - 1 ;
        }else{
            s = mid + 1 ;
        }
        mid = s + ( e - s ) / 2 ;
    }
    return ans ;
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> p(2);
        p[0] = firstocc(nums , target );
        p[1] = lastocc(nums , target );
        return p ;
    }
};