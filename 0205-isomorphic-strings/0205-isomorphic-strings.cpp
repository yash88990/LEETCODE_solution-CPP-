class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>sindex(256,0) , tindex(256, 0);
        for(int i = 0 ; i < s.size() ; i++){
            if(sindex[s[i]] != tindex[t[i]])return false;
            sindex[s[i]] = i+1;
            tindex[t[i]] = i+1;
        }
        return true;
    }
};