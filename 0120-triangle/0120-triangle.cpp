#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        // Start from the second last row and work upwards
        for (int i = triangle.size() - 2; i >= 0; --i) {
            // Update each element in the current row with the minimum path sum
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        // The top element of the triangle will now contain the minimum path sum
        return triangle[0][0];
    }
};