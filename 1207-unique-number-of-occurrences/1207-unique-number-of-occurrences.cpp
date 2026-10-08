class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int num : arr)freq[num]++;
        vector<int>ans;
        for(auto &entry : freq){
            ans.push_back(entry.second);
        }
        set<int>s(ans.begin() , ans.end());
        return s.size() == ans.size();
    }
};