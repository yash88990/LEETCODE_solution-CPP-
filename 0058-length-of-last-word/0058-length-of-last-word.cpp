class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word , lastword;
        while(ss >>word)lastword = word;
        return lastword.length();
        
    }
};