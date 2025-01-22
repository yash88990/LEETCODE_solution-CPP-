class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(); // row
        int m = isWater[0].size(); // coln
        vector<vector<int>> ans(n , vector<int>(m , -1));
        queue<pair<int,int>> q;
        //direction
        int x[4] = {0 , 0 ,1 , -1};
        int y[4] = {1,-1,0,0};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(int i = 0 ; i <  4; i++){
                int newI = top.first + y[i];
                int newJ = top.second + x[i];

                if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && ans[newI][newJ] == -1){
                    ans[newI][newJ] = ans[top.first][top.second] + 1 ;
                    q.push({newI , newJ});
                }
            }
        }
        return ans;
    }
};