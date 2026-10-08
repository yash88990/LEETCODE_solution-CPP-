class Solution {
public:
    string decodeString(string s) {
        stack<int>cnt;
        stack<string> strings;
        int count = 0 ;
        string result;
        for(char c : s){
            if(isdigit(c)){
                count = count * 10 + (c - '0');
            }else if(c == '['){
                cnt.push(count);
                strings.push(result);
                count = 0;
                result ="";
            }else if(c == ']'){
                int k = cnt.top();
                cnt.pop();
                string temp = result;
                for(int i = 1 ; i < k ; i++){
                    temp += result;
                }
                result = strings.top() + temp;
                strings.pop();
            }else{
                result += c;
            }
        }
        return result;
    }
};