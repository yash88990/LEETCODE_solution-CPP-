class Solution {
    private:
    bool isvowel(char ch){
         if(ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U'){
                return true;
            }
            return false;

    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        int start = 0 , end = n-1 ;
        while(start < end){
            while(start < end && !isvowel(s[start])) start++;
            while(start < end && !isvowel(s[end])) end--;
            if(start < end){
                swap(s[start++] , s[end--]);
            }
        }
        return s;
        
    }
};