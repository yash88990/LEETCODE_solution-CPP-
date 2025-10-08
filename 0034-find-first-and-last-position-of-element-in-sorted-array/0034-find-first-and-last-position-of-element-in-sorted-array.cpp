class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int  s= 0 , e = nums.size() -1;
        vector<int>ans;
        int f = -1  , l = -1;
        while(s <= e ){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                f = m;
                e = m - 1 ;
            }else if(nums[m] > target){
                e = m - 1 ;
            }else s = m + 1 ;
        }
        s = 0 , e = nums.size()-1;

        while(s <= e ){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                l = m;
                s = m + 1 ;
            }else if(nums[m] > target){
                e = m - 1 ;
            }else s = m + 1 ;
        }
        ans.push_back(f);
        ans.push_back(l);
        return ans;


    }
};