class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int maxLen = 0, left = 0, right = 0;
        
        while (right < s.length()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }
        
        return maxLen;
    }
    
};