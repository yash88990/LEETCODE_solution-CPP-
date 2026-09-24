class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int start = 0 , end = nums.size()-1 , ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == x)return mid;
            else if(nums[mid] > x){
                end = mid -1;
            }else{
                start = mid + 1 ;
                ans = mid;
            }
        }
        return ans+1;
    }
};