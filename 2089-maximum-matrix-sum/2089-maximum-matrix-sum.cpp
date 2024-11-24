class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0; // Sum of absolute values of all elements
        int negativeCount = 0; // Count of negative elements
        int minAbsValue = INT_MAX; // Minimum absolute value in the matrix

        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = matrix[i][j];
                totalSum += abs(value);
                if (value < 0) {
                    ++negativeCount;
                }
                minAbsValue = min(minAbsValue, abs(value));
            }
        }

        // If the count of negatives is odd, one smallest element will remain negative
        if (negativeCount % 2 == 0) {
            return totalSum;
        } else {
            return totalSum - 2 * minAbsValue;
        }
    }
};
