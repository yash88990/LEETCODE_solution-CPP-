class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>targetcount;
        for(auto i : t)targetcount[i]++;
        int required = targetcount.size();
        int formed = 0;
        unordered_map<char ,int> windowcount;
        int left = 0 , right = 0 , minleft = 0 , minlen = INT_MAX;
        while(right < s.size()){
            char c = s[right];
            windowcount[c]++;
            if(targetcount.find(c) != targetcount.end() && windowcount[c] == targetcount[c])formed++;
            while(left <= right && formed == required){
                if(right - left + 1 < minlen){
                    minlen = right - left +1 ;
                    minleft = left;
                }
                char leftchar = s[left];
                windowcount[leftchar]--;
                if(targetcount.find(leftchar) != targetcount.end() && windowcount[leftchar] < targetcount[leftchar]){
                    formed--;
                }
                left++;

            }
            right++;
        }
        return minlen == INT_MAX ? "" : s.substr(minleft , minlen);
    }
};