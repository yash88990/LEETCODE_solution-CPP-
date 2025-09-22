#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        
        // Using maps to store the frequency of rows and columns
        unordered_map<string, int> rowMap, colMap;
        
        // Count occurrences of rows
        for (int i = 0; i < n; ++i) {
            string rowStr = "";
            for (int j = 0; j < n; ++j) {
                rowStr += to_string(grid[i][j]) + ",";
            }
            rowMap[rowStr]++;
        }
        
        // Count occurrences of columns
        for (int j = 0; j < n; ++j) {
            string colStr = "";
            for (int i = 0; i < n; ++i) {
                colStr += to_string(grid[i][j]) + ",";
            }
            colMap[colStr]++;
        }
        
        // Find matching row and column pairs
        for (const auto& row : rowMap) {
            if (colMap.find(row.first) != colMap.end()) {
                count += row.second * colMap[row.first];
            }
        }
        
        return count;
    }
};