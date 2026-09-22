class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // Start with one empty subset
        vector<vector<int>> result = {{}};

        // Take each number one by one
        for (int num : nums) {

            // Store the new subsets we create
            vector<vector<int>> next;

            // Go through every existing subset
            for (auto subset : result) {

                // Make a copy of the current subset
                vector<int> temp = subset;

                // Add the current number to the subset
                temp.push_back(num);

                // Store the new subset
                next.push_back(temp);
            }

            // Add all new subsets to the existing result
            for (auto subset : next) {
                result.push_back(subset);
            }
        }

        // Return all possible subsets
        return result;
    }
};