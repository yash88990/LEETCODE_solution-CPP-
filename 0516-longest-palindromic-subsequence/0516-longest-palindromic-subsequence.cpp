class Solution {
public:
    int solve(string a , string b){
        vector<int> curr(b.length() + 1 , 0);
        vector<int> next(b.length() +1  , 0);
        for(int i = a.length() - 1 ; i>= 0; i--){
            for(int j = b.length() -1 ; j >= 0 ; j--){
                int ans = 0;
                if(a[i] == b[j])ans = 1 + next[j+1];
                else ans = max(next[j] , curr[j+1]);
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string newstr = s;
        reverse(newstr.begin() , newstr.end());
        return solve(s , newstr);
    }
};