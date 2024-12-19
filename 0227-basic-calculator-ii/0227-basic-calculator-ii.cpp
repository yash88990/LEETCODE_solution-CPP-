class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char lastop = '+';
        int num = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(isdigit(c)) num = num * 10 + ( c - '0');
            if((!isdigit(c) && !isspace(c)) || i == n - 1 ){
                if(lastop == '+')st.push(num);
                else if ( lastop == '-') st.push(-num);
                else if (lastop == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }else if (lastop == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                lastop = c;
                num = 0;

            }

        }
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result ;
    }
};