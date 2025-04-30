
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];
                if (current != '.') {
                    // Check row
                    if (rows[i].count(current) > 0)
                        return false;
                    rows[i].insert(current);
                    
                    // Check column
                    if (columns[j].count(current) > 0)
                        return false;
                    columns[j].insert(current);
                    
                    // Check 3x3 sub-box
                    int box_index = (i / 3) * 3 + j / 3;
                    if (boxes[box_index].count(current) > 0)
                        return false;
                    boxes[box_index].insert(current);
                }
            }
        }
        
        return true;
    }
};