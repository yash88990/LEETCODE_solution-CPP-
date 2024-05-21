class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets ;
        for(char c : s ) {
            if ( c == '('||  c == '['  || c == '{' ){
                brackets.push(c) ;
            }else{
                if(brackets.empty()) return false ;
                char top = brackets.top() ;
                brackets.pop();
                if( ( c ==')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{') ){
                    return false ;
                }
            }
        }
        return brackets.empty() ;
    }
};