class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0 , end = nums.size() - 1;
        int index = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] <= target){
                index = mid;
                start = mid + 1;
            }else{
                end = mid -1;
            }
            if(index != -1 && nums[mid] == target){
                return index;
            }
        }
        return index + 1;
    }
};