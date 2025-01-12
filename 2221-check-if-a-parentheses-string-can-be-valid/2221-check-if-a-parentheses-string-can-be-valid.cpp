class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; // Odd length cannot be valid

        // Forward pass: Check for enough '('
        int balance = 0; // Tracks excess '('
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0' || s[i] == '(') {
                balance++; // Treat unlocked or '(' as '('
            } else {
                balance--; // Treat ')' as ')'
            }
            if (balance < 0) return false; // Too many ')'
        }

        // Backward pass: Check for enough ')'
        balance = 0; // Tracks excess ')'
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') {
                balance++; // Treat unlocked or ')' as ')'
            } else {
                balance--; // Treat '(' as '('
            }
            if (balance < 0) return false; // Too many '('
        }

        // If both passes succeed, it's possible to make the string valid
        return true;
    }
};
