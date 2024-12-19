#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char lastOp = '+'; // To track the last operator
        int num = 0;       // To parse numbers
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // Parse the number
            }
            
            if ((!isdigit(c) && !isspace(c)) || i == n - 1) {
                if (lastOp == '+') {
                    st.push(num);
                } else if (lastOp == '-') {
                    st.push(-num);
                } else if (lastOp == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (lastOp == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                lastOp = c; // Update the last operator
                num = 0;    // Reset the number
            }
        }

        // Sum up all values in the stack
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
