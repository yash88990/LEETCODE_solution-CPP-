#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        
        // Map each value in mat to its row and column index
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                positionMap[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowPaint(m, 0), colPaint(n, 0);
        
        // Process each element in arr
        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            auto [row, col] = positionMap[val];
            
            // Increment paint count for the corresponding row and column
            if (++rowPaint[row] == n) return i; // Check if row is fully painted
            if (++colPaint[col] == m) return i; // Check if column is fully painted
        }
        
        return -1; // This line will never be reached given the constraints
    }
};
