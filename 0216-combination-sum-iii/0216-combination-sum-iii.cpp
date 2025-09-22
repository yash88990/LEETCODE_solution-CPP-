#include <vector>

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, 1, k, n);
        return result;
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, int start, int k, int target) {
        // Base case: If k is 0 and target is 0, add the combination to the result
        if (k == 0 && target == 0) {
            result.push_back(combination);
            return;
        }
        
        // Backtracking: Try adding numbers from start to 9
        for (int i = start; i <= 9; ++i) {
            // Add the current number to the combination
            combination.push_back(i);
            // Recur with one less number to choose, and the updated target
            backtrack(result, combination, i + 1, k - 1, target - i);
            // Backtrack: Remove the last added number to try a different combination
            combination.pop_back();
        }
    }
};