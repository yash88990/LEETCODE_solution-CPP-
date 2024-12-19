#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1; // +1 for positive, -1 for negative
        stack<int> st;
        int n = s.length();
        int i = 0;

        while (i < n) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num; // Add the parsed number to the result
                continue;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(result); // Save the current result
                st.push(sign);   // Save the current sign
                result = 0;      // Reset result for the new sub-expression
                sign = 1;        // Reset sign
            } else if (c == ')') {
                result = st.top() * result; // Multiply by the sign before the '('
                st.pop();
                result += st.top(); // Add the result before the '('
                st.pop();
            }
            i++;
        }
        return result;
    }
};
