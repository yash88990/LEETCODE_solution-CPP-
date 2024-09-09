class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Step 1: Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Step 2: Initialize the boundaries
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        ListNode* current = head;
        
        // Step 3: Spiral traversal
        while (current != nullptr) {
            // Traverse from left to right across the top boundary
            for (int i = left; i <= right && current != nullptr; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            ++top; // Move the top boundary down
            
            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom && current != nullptr; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            --right; // Move the right boundary left
            
            // Traverse from right to left across the bottom boundary
            for (int i = right; i >= left && current != nullptr; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            --bottom; // Move the bottom boundary up
            
            // Traverse from bottom to top along the left boundary
            for (int i = bottom; i >= top && current != nullptr; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            ++left; // Move the left boundary right
        }
        
        // Step 4: Return the filled matrix
        return matrix;
    }
};
