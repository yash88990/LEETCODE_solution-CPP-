class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, temp, used, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used, vector<vector<int>>& result) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, temp, used, result);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
};
