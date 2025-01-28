class Solution {
public:
int dfs(vector<vector<int>>& grid , int r , int c ){

    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 )return 0;

    int fish = grid[r][c];
    grid[r][c] = 0 ;
    //adjacent 
    fish += dfs(grid , r+1 , c);
    fish += dfs(grid , r-1 , c);
    fish += dfs(grid , r , c +  1 );
    fish += dfs(grid , r , c - 1 );
    return fish;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int maxfish = 0 ;
        for(int r = 0 ; r < grid.size() ; r++){
            for(int c = 0 ; c < grid[0].size() ; c++){
                if(grid[r][c] > 0){
                    maxfish = max(maxfish , dfs(grid , r ,  c));
                }
            }
        }
        return maxfish;
    }
};