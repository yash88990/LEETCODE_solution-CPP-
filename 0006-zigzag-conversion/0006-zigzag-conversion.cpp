class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size() , r = numRows;
        if(r == 1 || r >= n)return s;
        int currrow = 0 ;
        bool goingdown = false;
        vector<string> rows(r);
        for(char c : s){
            rows[currrow] += c;
            if(currrow == 0 || currrow == r-1){
                goingdown = !goingdown;
            }
            currrow += goingdown ? 1 : -1;
        }
        string ans;
        for(auto c : rows)ans += c;
        return ans;

        
    }
};