class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[i-1]){
                nums[i-1] = 2 * nums[i-1];
                nums[i] = 0;
            }
        }
        vector<int> ans ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0) ans.push_back(nums[i]);
        }
        for(int i = ans.size() ;i < n ; i++ ){
            ans.push_back(0);
        }
        return ans;
    }
};