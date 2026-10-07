class Solution {
public:
    bool isvowel(char ch){
        char c = tolower(ch);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0 , j = s.size() - 1 ;
        while(  i < j){
            while(i < j && !isvowel(s[i]))i++;
            while( i < j && !isvowel(s[j]))j--;
            swap(s[i] , s[j]);
            i++;
            j--;
        }
        return s;
    }
};