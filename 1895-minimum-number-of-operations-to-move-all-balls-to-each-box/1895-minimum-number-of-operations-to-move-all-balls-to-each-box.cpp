class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        
        // Left-to-right pass
        int count = 0; // Number of balls encountered
        int operations = 0; // Cumulative operations
        for (int i = 0; i < n; i++) {
            result[i] += operations;
            count += boxes[i] == '1' ? 1 : 0; // Count balls
            operations += count; // Increment operations
        }
        
        // Right-to-left pass
        count = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; i--) {
            result[i] += operations;
            count += boxes[i] == '1' ? 1 : 0; // Count balls
            operations += count; // Increment operations
        }
        
        return result;
    }
};
