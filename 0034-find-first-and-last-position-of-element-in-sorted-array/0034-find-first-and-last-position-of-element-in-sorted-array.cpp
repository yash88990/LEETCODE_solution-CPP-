class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0 , end = nums.size()-1 , first = -1 , last = -1;
        //first position 
        while(start <= end){
            int mid = start + ( end - start)/2;
            if(nums[mid] == target){
                first = mid;
                end = mid - 1 ;
            }else if(nums[mid] > target)end = mid - 1;
            else start = mid + 1 ;
        }
        start = 0 , end = nums.size()-1;
        //last position 
        while(start <= end){
            int mid = start + ( end - start)/2;
            if(nums[mid] == target){
                last = mid;
                 start =mid + 1 ;
            }else if(nums[mid] > target)end = mid - 1;
            else start = mid + 1 ;
        }
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};