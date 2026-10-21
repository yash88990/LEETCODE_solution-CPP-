class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word ;
        vector<string>ans;
        while(ss >>word)ans.push_back(word);
        return ans[ans.size()-1].length();
        
    }
};