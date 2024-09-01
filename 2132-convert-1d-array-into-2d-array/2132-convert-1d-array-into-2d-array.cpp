class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if it's possible to create an m x n array
        if (original.size() != m * n) {
            return {};  // Return empty 2D array if not possible
        }
        
        vector<vector<int>> result(m, vector<int>(n));  // Initialize the 2D array
        
        // Fill the 2D array using elements from the original array
        for (int i = 0; i < original.size(); i++) {
            int row = i / n;  // Determine the row index
            int col = i % n;  // Determine the column index
            result[row][col] = original[i];
        }
        
        return result;  // Return the constructed 2D array
    }
};
