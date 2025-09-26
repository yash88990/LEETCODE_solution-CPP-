class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num : arr)freq[num]++;
        unordered_set<int> unique;
        for(auto &entry : freq){
            if(unique.find(entry.second) != unique.end())return false;
            unique.insert(entry.second);
        }
        return true;

        
    }
};