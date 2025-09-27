class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string,int> r , c;
        for(int i = 0 ; i < n ; i++){
            string row = "" , col = "";
            for(int j = 0 ;j < n ; j++){
                row += to_string(grid[i][j]) + ",";
                col += to_string(grid[j][i]) + ",";
            }
            r[row]++;
            c[col]++;
        }
        int count = 0;
        for(const auto& rows : r){
            if(c.find(rows.first) != c.end()){
                count += rows.second * c[rows.first];
            }
        }
        return count;


    }
};