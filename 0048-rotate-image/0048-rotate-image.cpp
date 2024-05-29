#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // Traverse each layer of the matrix
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer;
            int last = n - 1 - layer;

            // Iterate through each element in the current layer
            for (int i = first; i < last; ++i) {
                int offset = i - first;
                int top = matrix[first][i];

                // Rotate the elements clockwise
                // Move left element to top
                matrix[first][i] = matrix[last - offset][first];
                // Move bottom element to left
                matrix[last - offset][first] = matrix[last][last - offset];
                // Move right element to bottom
                matrix[last][last - offset] = matrix[i][last];
                // Move top element to right
                matrix[i][last] = top;
            }
        }
    }
};
