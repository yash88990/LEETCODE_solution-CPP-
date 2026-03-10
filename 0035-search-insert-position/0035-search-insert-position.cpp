class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0 , end = nums.size() - 1 , ans = nums.size();
        while(start <= end){
            int mid = start + ( end - start)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target){
                ans = mid;
                end = mid -1;
            }else start = mid + 1;
        }
        return ans;
    }
};