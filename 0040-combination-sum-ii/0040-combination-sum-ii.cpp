class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates

            if (candidates[i] > target) break; // no need to continue if the current candidate is greater than the target

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result); // move to the next index
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end()); // sort to handle duplicates and simplify the problem
        backtrack(candidates, target, 0, current, result);

        return result;
    }
};
