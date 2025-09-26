class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int cnt = 0 , n = s.size() ;
        for(int i = 0 ; i < k ; i++){
            if(isvowel(s[i]))cnt++;
        }
        int maxi = cnt;
        for(int i = k ; i < n ; i++){
            if(isvowel(s[i]))cnt++;
            if(isvowel(s[i - k]))cnt--;
            maxi = max(cnt , maxi);
        }
        return maxi;
    }
};