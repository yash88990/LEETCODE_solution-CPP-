class Solution {
    private:
    int solve(vector<int>& nums, int target , int start , int end ){
        //base case 
        if(start > end) return -1;
        int mid = start + ( end - start ) /  2;
        if(nums[mid] == target) return mid;
        else if (nums[mid] > target) return solve(nums , target , start , mid - 1 );
        else return solve(nums , target , mid + 1 , end);
    }
public:
    
    int search(vector<int>& nums, int target) {
        int ans = solve(nums , target , 0 , nums.size() - 1 );
        return ans;
    }
};