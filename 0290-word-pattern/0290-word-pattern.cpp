class Solution {
public:
    bool wordPattern(string pattern, string s) {
       
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word)words.push_back(word);
        unordered_map<char,int> pmap;
        unordered_map<string , int> wmap;
        if(pattern.size() != words.size())return false;
        for(int i = 0 ; i < pattern.size() ; i++){
            char ch = pattern[i];
            string w = words[i];
            if(pmap[ch] != wmap[w])return false;
            pmap[ch]=i+1;
            wmap[w]=i+1;
        }
        return true;
    }
};