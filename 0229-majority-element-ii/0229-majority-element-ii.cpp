class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>ans;
        unordered_map<int,int> freq;
        for(int num :nums)freq[num]++;
        for(auto &entry : freq){
            if(entry.second > n/3) ans.push_back(entry.first);
        }
        return ans;
    }
};