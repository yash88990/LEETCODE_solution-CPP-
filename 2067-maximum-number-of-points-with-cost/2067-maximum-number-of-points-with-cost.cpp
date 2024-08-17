class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<long long> prevRow(points[0].begin(), points[0].end());

        // Iterate over each row starting from the second row
        for (int i = 1; i < m; ++i) {
            vector<long long> leftMax(n), rightMax(n), currRow(n);
            
            // Calculate left max array for the current row
            leftMax[0] = prevRow[0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1], prevRow[j] + j);
            }
            
            // Calculate right max array for the current row
            rightMax[n - 1] = prevRow[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1], prevRow[j] - j);
            }
            
            // Calculate the max points for the current row
            for (int j = 0; j < n; ++j) {
                currRow[j] = max(leftMax[j] - j, rightMax[j] + j) + points[i][j];
            }
            
            // Move to the next row
            prevRow = currRow;
        }
        
        // The result will be the maximum value in the last row
        return *max_element(prevRow.begin(), prevRow.end());
    }
};
