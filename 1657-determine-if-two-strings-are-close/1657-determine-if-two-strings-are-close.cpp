class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 != n2)return false;
        unordered_map<char,int>freq1,freq2;
        unordered_set<char>ch1,ch2;
        for(char c : word1){
            freq1[c]++;
            ch1.insert(c);
        }
        for(char c : word2){
            freq2[c]++;
            ch2.insert(c);
        }
        vector<int> f1 , f2;
        for(auto &entry : freq1){
            f1.push_back(entry.second);
        }
        for(auto &entry : freq2){
            f2.push_back(entry.second);
        }
        sort(f1.begin() , f1.end());
        sort(f2.begin() , f2.end());
        return f1 == f2 && ch1 == ch2;
    }
};