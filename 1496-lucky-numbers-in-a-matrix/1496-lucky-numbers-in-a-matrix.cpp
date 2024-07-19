#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Step 1: Find the minimum element in each row
        vector<int> minRowValues(m);
        for (int i = 0; i < m; ++i) {
            minRowValues[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }
        
        // Step 2: Check if the minimum element in each row is the maximum in its column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minRowValues[i]) {
                    bool isMaxInColumn = true;
                    for (int k = 0; k < m; ++k) {
                        if (matrix[k][j] > matrix[i][j]) {
                            isMaxInColumn = false;
                            break;
                        }
                    }
                    if (isMaxInColumn) {
                        luckyNumbers.push_back(matrix[i][j]);
                    }
                }
            }
        }
        
        return luckyNumbers;
    }
};
