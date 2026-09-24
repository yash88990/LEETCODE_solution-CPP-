class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0 , end = nums.size()-1 ;
        while(start <= end){
            int mid = start + ( end - start)/2;
            if(nums[mid] == target)return true;
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue;
            }
            else if(nums[start] <= nums[mid]){//left part is sorted
                //is target lies in this part
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid - 1 ;
                }else start = mid + 1 ;
            }else{//right part is sorted
                 if(target >= nums[mid] && target <= nums[end]){
                    start = mid + 1 ;
                 }else end = mid - 1 ;

            }
        }
        return false;
    }
};