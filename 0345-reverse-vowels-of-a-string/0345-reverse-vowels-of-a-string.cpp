class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c ){
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int start = 0 , end = s.size() - 1 ;
        while(start < end ){
            while(start < end && !isVowel(s[start])){
                start++;
            }
            while(start < end && !isVowel(s[end])){
                end--;
            }
            if(start < end ){
                swap(s[start++] , s[end--]);
            }
        }
        return s ;
    }
};