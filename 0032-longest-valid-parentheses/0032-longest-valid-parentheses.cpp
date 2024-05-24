class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> stk;
        stk.push(-1); // Initialize stack with a dummy index
        
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i); // Update the index of the last unmatched ')' character
                } else {
                    maxLen = std::max(maxLen, i - stk.top());
                }
            }
        }
        
        return maxLen;
    }
};