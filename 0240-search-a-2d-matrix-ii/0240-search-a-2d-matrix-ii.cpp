class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
        return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            // If the current element is less than the target, move down to the next row
            row++;
        } else {
            // If the current element is greater than the target, move left to the previous column
            col--;
        }
    }

    return false;
    }
};