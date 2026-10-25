class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin() , nums.end());
        int maxi = 0;
        for(int num : s){
            if(s.find(num - 1) == s.end()){
                int start = num;
                int cnt = 1 ;
                while(s.find(start + 1) != s.end()){
                    start++;
                    cnt++;
                }
                maxi = max(maxi , cnt);
            }
        }
        return maxi;
    }
};