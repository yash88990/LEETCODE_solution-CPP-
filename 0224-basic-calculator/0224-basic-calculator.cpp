class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int currentResult = 0;  // Store the current result
        int sign = 1;           // 1 for positive, -1 for negative
        int i = 0;

        while (i < s.size()) {
            char ch = s[i];
            if (isdigit(ch)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                currentResult += sign * num;  // Apply the sign to the number
                i--;  // Adjust index because the loop will increment it
            } else if (ch == '+') {
                sign = 1;  // Set positive sign
            } else if (ch == '-') {
                sign = -1;  // Set negative sign
            } else if (ch == '(') {
                stk.push(currentResult);  // Save the current result
                stk.push(sign);           // Save the current sign
                currentResult = 0;        // Reset for new sub-expression
                sign = 1;                 // Default positive sign
            } else if (ch == ')') {
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                currentResult = prevResult + prevSign * currentResult;
            }
            i++;  // Move to the next character
        }

        return currentResult;
    }
};
