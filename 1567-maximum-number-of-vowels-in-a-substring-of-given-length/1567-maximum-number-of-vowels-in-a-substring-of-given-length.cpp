class Solution {
public:  
    bool isvowel(char ch){
        char c = tolower(ch);
        if(c == 'a' || c =='e' || c =='i' || c == 'o' || c == 'u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int vowelcount = 0;
        int n = s.length();
        for(int i = 0 ; i < k ; i++){
            if(isvowel(s[i]))vowelcount++;
        }
        int maxi = vowelcount;
        for(int i = k ; i < n ; i++){
            if (isvowel(s[i - k])) vowelcount--;
            if (isvowel(s[i]))  vowelcount++;
            
            maxi = max(vowelcount , maxi);
        }
        return maxi;
    }
};