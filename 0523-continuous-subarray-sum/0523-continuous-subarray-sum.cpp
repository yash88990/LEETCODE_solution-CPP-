class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mod_map;
        mod_map[0] = -1;  // To handle cases where the subarray starts from index 0
        int cumulative_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            cumulative_sum += nums[i];
            int mod = cumulative_sum % k;
            
            if (mod_map.find(mod) != mod_map.end()) {
                if (i - mod_map[mod] > 1) {
                    return true;
                }
            } else {
                mod_map[mod] = i;
            }
        }
        
        return false;
    }
};
