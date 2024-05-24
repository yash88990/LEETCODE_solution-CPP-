#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);
        
        // Sort the numbers to handle duplicates
        std::sort(nums.begin(), nums.end());
        
        // Start the backtracking process
        backtrack(nums, used, current, result);
        
        return result;
    }
    
private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& used, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if the current permutation is the same size as nums, add it to the result
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Iterate over the numbers
        for (int i = 0; i < nums.size(); ++i) {
            // Skip used elements or duplicates
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            
            // Include the element in the current permutation
            current.push_back(nums[i]);
            used[i] = true;
            
            // Recurse
            backtrack(nums, used, current, result);
            
            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }
};
