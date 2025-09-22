#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        
        // Process each character in the string
        for (char c : s) {
            if (c == '*') {
                if (!stk.empty()) {
                    stk.pop();  // Remove the closest non-star character to the left
                }
            } else {
                stk.push(c);  // Retain non-star characters
            }
        }
        
        // Construct the resulting string from the stack
        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        // The characters are in reverse order, so reverse the result
        reverse(result.begin(), result.end());
        
        return result;
    }
};