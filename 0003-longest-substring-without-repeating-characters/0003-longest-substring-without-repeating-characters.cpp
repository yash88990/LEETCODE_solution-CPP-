class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> map;
        int maxlen = 0;
        int left = 0;
        for(int right = 0 ; right < s.size() ; right++){
            if(map.find(s[right]) != map.end() && 
                    map[s[right]] >= left){
                left = map[s[right]] + 1;
            }
            map[s[right]] = right ;
            maxlen = max(maxlen , right - left + 1 );
        }
        return maxlen;
    }
};