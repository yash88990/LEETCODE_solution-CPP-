class Solution {
public:
    string removeStars(string s) {
        stack<int> stk;
        for(char c : s){
            if(c == '*'){
                //pop
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else{
                //push
                stk.push(c);
            }
        }
        string ans = "";
        while(!stk.empty()){
            char ch = stk.top();
            stk.pop();
            ans += ch;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};