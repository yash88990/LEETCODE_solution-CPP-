class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Create a copy of the heights array and sort it to get the expected order
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        
        // Initialize a counter to count the mismatches
        int mismatchCount = 0;
        
        // Compare each element in heights with the corresponding element in expected
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                mismatchCount++;
            }
        }
        
        // Return the count of mismatches
        return mismatchCount;
    }
};
