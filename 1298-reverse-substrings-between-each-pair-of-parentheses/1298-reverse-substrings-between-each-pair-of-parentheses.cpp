class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stack ;
        for(int i = 0 ; i < s.length() ; i++ ){
            if(s[i] == '('){
                stack.push(i);
            }else if(s[i] == ')'){
                int start = stack.top() ;
                stack.pop();
                reverse(s.begin() + start + 1 , s.begin() + i);
            }
        }
        string result ;
        for(char c : s ){
            if(c != '(' && c != ')'){
                result += c ;
            }
        }
        return result ;
    }
};