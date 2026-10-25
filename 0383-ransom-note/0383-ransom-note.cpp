class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> rmap , mmap;
        for(char ch : r)rmap[ch]++;
        for(char ch : m)mmap[ch]++;
        for(auto pair: rmap){
            char ch = pair.first;
            int freq = pair.second;
            if(mmap[ch] < freq)return false;
        }
        return true;
    }
};