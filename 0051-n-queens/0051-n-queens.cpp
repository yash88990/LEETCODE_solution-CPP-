#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize the board with empty squares
        
        solveNQueensHelper(board, 0, solutions);
        
        return solutions;
    }
    
private:
    void solveNQueensHelper(vector<string>& board, int row, vector<vector<string>>& solutions) {
        if (row == board.size()) { // Base case: if all queens are placed successfully
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < board.size(); ++col) {
            if (isValidMove(board, row, col)) {
                board[row][col] = 'Q'; // Place the queen
                solveNQueensHelper(board, row + 1, solutions); // Recur for the next row
                board[row][col] = '.'; // Backtrack: remove the queen for other possibilities
            }
        }
    }
    
    bool isValidMove(vector<string>& board, int row, int col) {
        // Check if there is no queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q')
                return false;
        }
        
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
};
