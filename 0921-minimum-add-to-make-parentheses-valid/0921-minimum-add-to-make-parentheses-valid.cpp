class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;  // Count of unmatched '('
        int closeCount = 0; // Count of unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                openCount++; // Found an unmatched opening parenthesis
            } else { // c == ')'
                if (openCount > 0) {
                    openCount--; // Found a matching pair, reduce openCount
                } else {
                    closeCount++; // Unmatched closing parenthesis, increment closeCount
                }
            }
        }
        
        // Total moves = unmatched opening parentheses + unmatched closing parentheses
        return openCount + closeCount;
    }
};