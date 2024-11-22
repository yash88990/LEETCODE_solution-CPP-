#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (const auto& row : matrix) {
            string normalized = "";
            // Use the first element of the row to determine normalization
            for (int cell : row) {
                // Normalize based on the first element of the row
                normalized += to_string(cell ^ row[0]);
            }
            // Increment the count for the normalized pattern
            patternCount[normalized]++;
            maxRows = max(maxRows, patternCount[normalized]);
        }

        return maxRows;
    }
};
