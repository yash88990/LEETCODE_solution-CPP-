#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Assign the minimum of the remaining row sum and column sum
                int value = std::min(rowSum[i], colSum[j]);
                matrix[i][j] = value;
                
                // Update the rowSum and colSum
                rowSum[i] -= value;
                colSum[j] -= value;
            }
        }
        
        return matrix;
    }
};
