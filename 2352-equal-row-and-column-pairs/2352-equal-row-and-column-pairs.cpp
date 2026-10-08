class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> rowmap , colmap;
        for(int i = 0 ; i < n ; i++){
            string row ="";
            for(int j = 0 ; j < n ; j++){
                row += to_string(grid[i][j]) + ",";
            }
            rowmap[row]++;
        }
        for(int i = 0 ; i < n ; i++){
            string col ="";
            for(int j = 0 ; j < n ; j++){
                col += to_string(grid[j][i]) + ",";
            }
            colmap[col]++;
        }
        int cnt = 0;
        for(const auto& row : rowmap){
            if(colmap.find(row.first) != colmap.end()){
                cnt += row.second * colmap[row.first];
            }
        }
        return cnt;

    }
};