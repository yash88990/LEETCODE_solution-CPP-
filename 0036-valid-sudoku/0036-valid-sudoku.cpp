class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        unordered_set<char>row[9],col[9],box[9];
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(board[i][j] == '.')continue;
                char val = board[i][j];
                int boxindex = (i/3) * 3 + j/3;
                if(row[i].count(val) || col[j].count(val) || box[boxindex].count(val))return false;
                row[i].insert(val);
                col[j].insert(val);
                box[boxindex].insert(val);
            }
        }
        return true;
    }
};