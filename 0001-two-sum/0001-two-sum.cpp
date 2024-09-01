class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> nums_map ;
        for(int i = 0 ; i , nums.size() ; i++ ){
            int complement = target - nums[i] ;
            if(nums_map.find(complement) != nums_map.end()){
                return {nums_map[complement] , i };
            }
            nums_map[nums[i]] = i;
        }
        return {};
    }
};