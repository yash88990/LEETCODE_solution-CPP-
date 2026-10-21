class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(),s.end());
        string f = s.front() , b = s.back();
        int i = 0 ;
        while(i < f.size() && i < b.size() && f[i] == b[i])i++;
        return f.substr(0,i);


    }
};