#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1); // Base case to handle edge cases
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push(i); // Push index of '('
            } else {
                stack.pop(); // Pop the top (matching '(' or base case `-1`)
                if (stack.empty()) {
                    stack.push(i); // Push current index as a new base
                } else {
                    maxLen = max(maxLen, i - stack.top()); // Update max length
                }
            }
        }

        return maxLen;
    }
};
