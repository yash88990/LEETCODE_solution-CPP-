class Solution {
public:
    int hammingWeight(int n) {
          string ans = "";
           while( n != 0){
               int d = n % 2 ;
               ans = to_string(d) + ans;
               n /= 2 ;
           }
           int cnt = 0;
           for (int i = 0; i < ans.length(); i++){
            if(ans[i] == '1')cnt++;
           }
           return cnt;
    }
};