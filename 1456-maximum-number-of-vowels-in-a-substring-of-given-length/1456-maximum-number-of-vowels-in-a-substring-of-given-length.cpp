class Solution {
public:
    bool isvowel(char ch){
        char c = tolower(ch);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        else return false;
    }
    int maxVowels(string s, int k) {

        int cnt = 0;
        for(int i = 0 ; i < k ; i++){
            if(isvowel(s[i]))cnt++;
        }
        int maxi = cnt;
        for(int i = k ; i < s.size() ; i++){
            if(isvowel(s[i]))cnt++;
            if(isvowel(s[i-k]))cnt--;
            maxi = max(maxi , cnt);
        }
        return maxi;
    }
};