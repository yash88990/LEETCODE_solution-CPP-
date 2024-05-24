class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
    void backtrack(const std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, current, result);
                current.pop_back();
            }
        }
    }
};