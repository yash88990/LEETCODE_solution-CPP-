class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1,-1,-1, 0,0, 1,1,1};
        int dc[] = {-1 , 0 , 1 , -1, 1 , -1 , 0 , 1};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m  ; j++){
                int cnt = 0;
                for(int k = 0 ; k < 8 ; k++){
                    int nr = i+ dr[k];
                    int nc = j + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(board[nr][nc] == 1 || board[nr][nc] == -1)cnt++;
                    }
                }
                if(board[i][j] == 1 && (cnt < 2 || cnt > 3))board[i][j] = -1;
                else if(board[i][j] == 0 && cnt == 3)board[i][j] = 2;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == -1)board[i][j] = 0;
                else if(board[i][j] > 0)board[i][j] = 1;
            }
        }
    }
};