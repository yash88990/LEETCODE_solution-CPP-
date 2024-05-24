class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
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
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) // Skip duplicates
                continue;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result); // Use i + 1 to avoid reusing the same element
            current.pop_back();
        }
    }
};