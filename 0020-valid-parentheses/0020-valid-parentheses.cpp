#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        
        for (char c : s) {
            // Push opening brackets to the stack
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                // For closing brackets, check for matching opening brackets
                if (stack.empty()) {
                    return false; // No opening bracket available
                }
                if ((c == ')' && stack.top() != '(') ||
                    (c == '}' && stack.top() != '{') ||
                    (c == ']' && stack.top() != '[')) {
                    return false; // Mismatched bracket
                }
                stack.pop(); // Valid match, remove the opening bracket
            }
        }
        
        // If stack is empty, all brackets matched correctly
        return stack.empty();
    }
};
