#include <string>
#include <stack>
#include <algorithm> // For std::reverse

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> stack;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')') {
                int start = stack.top();
                stack.pop();
                std::reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        std::string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }
        
        return result;
    }
};
