class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())return false;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row = 0 ;
        int col = columns - 1;
        while(row < rows && col >= 0){
            if(matrix[row][col] == target)return true;
            else if(matrix[row][col] < target)row++;
            else col--;
        }
        return false;
    }
};