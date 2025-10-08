class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int totalOnes = INT_MIN, minRow = INT_MAX;
        for (int i = 0; i < m; i++) {
            int onesCount = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    onesCount++;
            }
            if (totalOnes < onesCount) {
                minRow = i;
                totalOnes = onesCount;
            }
        }

        return {minRow, totalOnes};
    }
};