class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0] , entrance[1]} , 0});
        maze[entrance[0]][entrance[1]] = '+';
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0 ,-1,1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first.first;
            int c = curr.first.second;
            int steps = curr.second;
            if( (r == 0 || r == n-1 || c == 0 || c == m-1 ) && (r != entrance[0] || c != entrance[1]) ){
                return steps;
            }
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m  && maze[nr][nc] == '.'){
                    maze[nr][nc] = '+';
                    q.push({{nr , nc} , steps + 1});
                }
            }
        }
        return -1;
    }
};