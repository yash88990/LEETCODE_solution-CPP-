class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> st;
        int i = 0;
        while(i <  s.size()){
            char c = s[i];
            if(isdigit(c)){
                int num = 0 ;
                while(i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue;
            }else if ( c == '+'){
                sign = 1 ;
            }else if (c == '-') {
                sign = -1;
            }else if ( c == '('){
                st.push(result);
                st.push(sign);
                result = 0 ;
                sign = 1;
            }
            else if ( c == ')'){
                result = st.top() * result ;
                st.pop();
                result += st.top();
                st.pop();

            }
            i++;
        }
        return result ;
    }
};