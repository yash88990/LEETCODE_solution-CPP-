class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {
            {0,1},{1,0},{0,-1},{-1,0}
        };
        unordered_map<int , int> area;
        int index = 2 , maxarea = 0 ;
        function<int(int,int,int)> dfs = [&](int r , int c , int index){
            if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1 )return 0;
            grid[r][c] = index;
            int size = 1 ;
            for(auto& d : directions){
                size += dfs( r + d[0] , c + d[1],index);
                
            }
            return size;
        };
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                if(grid[r][c] == 1 ){
                    area[index] = dfs(r , c , index);
                    maxarea = max(maxarea , area[index]);
                    index++;
                }
            }
        }
        for(int r = 0 ; r < n ; r++){
            for( int c = 0 ; c < n ; c++){
                if(grid[r][c] == 0 ){
                    unordered_set<int> seen;
                    int newsize = 1 ;
                    for(auto& d : directions){
                        int nr = r + d[0] , nc = c + d[1];
                        if(nr >= 0 && nc>= 0 && nr < n && nc < n  && grid[nr][nc]>1){
                            seen.insert(grid[nr][nc]);
                        }

                    }
                    for(int inx : seen){
                        newsize += area[inx];

                    }
                    maxarea = max (maxarea , newsize);
                }
            }
        }
        return maxarea;
    }
};