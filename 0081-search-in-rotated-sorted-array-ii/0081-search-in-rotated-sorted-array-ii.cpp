class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int start = 0 , end = n-1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target)return true;
            else if (nums[mid] > target) end = mid - 1;
            else start = mid + 1 ;
        }
        return false;
    }
};