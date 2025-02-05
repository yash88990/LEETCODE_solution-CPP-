class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size())return false;
        vector<int> diff;
        for(int i = 0 ;i < s1.size();i++){
            if(s1[i] != s2[i]){
                diff.push_back(i);
                if(diff.size() > 2 )return false;
            }
        }
        if(diff.empty())return true;
        return (diff.size() == 2 &&
                 s1[diff[0]] == s2[diff[1]] &&
                 s1[diff[1]] == s2[diff[0]]);

    }
};