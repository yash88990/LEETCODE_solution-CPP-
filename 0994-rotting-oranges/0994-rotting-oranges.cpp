class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int freshcount = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshcount++;
                }
            }
        }
        if(freshcount == 0)return 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            bool rotten = false;
            for(int i = 0 ; i < size ; i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(int j = 0 ; j < 4 ; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        freshcount--;
                        rotten = true;
                    }
                }
            }
             if(rotten)minutes++;
        }
       
        return freshcount == 0 ? minutes : -1;
    }
};