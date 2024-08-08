#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 1;  // The initial step size
        int dirIndex = 0;  // Start with the 'right' direction
        result.push_back({rStart, cStart});  // Add the starting position
        int totalCells = rows * cols;
        
        while (result.size() < totalCells) {
            for (int i = 0; i < 2; ++i) {  // Two turns: horizontal and vertical
                for (int j = 0; j < steps; ++j) {
                    rStart += directions[dirIndex][0];
                    cStart += directions[dirIndex][1];
                    
                    // Check if the current position is within bounds
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                }
                dirIndex = (dirIndex + 1) % 4;  // Turn 90 degrees clockwise
            }
            steps++;  // Increase the step size after every two turns
        }
        
        return result;
    }
};
