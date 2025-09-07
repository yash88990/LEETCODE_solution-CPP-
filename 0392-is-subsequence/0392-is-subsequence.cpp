class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;
        int tIndex = 0;
        
        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] == t[tIndex]) {
                sIndex++;
            }
            tIndex++;
        }
        
        return sIndex == s.length();
    }
};