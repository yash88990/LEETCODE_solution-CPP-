class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Step 1: Identify zero locations
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) firstRowZero = true;
                    if(j == 0) firstColZero = true;
                    matrix[i][0] = 0;  // Mark first column
                    matrix[0][j] = 0;  // Mark first row
                }
            }
        }

        // Step 2: Use markers to set zeros (except first row and first column)
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Set first row and column to zero if needed
        if(firstRowZero) {
            for(int j = 0; j < col; j++) matrix[0][j] = 0;
        }
        if(firstColZero) {
            for(int i = 0; i < row; i++) matrix[i][0] = 0;
        }
    }
};
