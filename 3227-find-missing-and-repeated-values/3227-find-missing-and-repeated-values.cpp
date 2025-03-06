class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        int repeated = -1, missing = -1;
        
        // Step 1: Find the repeated number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                if (seen.count(num)) {
                    repeated = num;  // Found duplicate
                }
                seen.insert(num);
            }
        }
        
        // Step 2: Find the missing number
        for (int num = 1; num <= n * n; num++) {
            if (!seen.count(num)) {
                missing = num;
                break;
            }
        }
        
        return {repeated, missing};
    }
};
