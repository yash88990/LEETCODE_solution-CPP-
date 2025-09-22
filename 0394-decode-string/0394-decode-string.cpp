#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        string result;
        int count = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                count = count * 10 + (c - '0'); // Accumulate the count
            } else if (c == '[') {
                counts.push(count);
                strings.push(result);
                result = ""; // Reset result for the new nested string
                count = 0; // Reset count
            } else if (c == ']') {
                int repeatCount = counts.top();
                counts.pop();
                string repeatedString = result;
                for (int i = 1; i < repeatCount; ++i) {
                    repeatedString += result;
                }
                result = strings.top() + repeatedString;
                strings.pop();
            } else {
                result += c; // Accumulate characters
            }
        }
        
        return result;
    }
};