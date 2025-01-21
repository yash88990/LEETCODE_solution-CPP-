class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);

        // Calculate prefix sums for the top and bottom rows
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }

        long long result = LLONG_MAX;

        // Simulate the split at each column
        for (int i = 0; i < n; ++i) {
            long long pointsAbove = prefixTop[n] - prefixTop[i + 1]; // Points left in the top row after the split
            long long pointsBelow = prefixBottom[i];               // Points collected in the bottom row before the split
            long long secondRobotPoints = max(pointsAbove, pointsBelow);
            result = min(result, secondRobotPoints);
        }

        return result;
    }
};
