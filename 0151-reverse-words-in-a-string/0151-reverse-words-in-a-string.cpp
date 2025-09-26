class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word , result;
        vector<string>newwords;
        while(ss >> word)newwords.push_back(word);
        reverse(newwords.begin() , newwords.end());
        for(int i = 0 ; i < newwords.size() ; i++){
            result += newwords[i];
            if(i < newwords.size() - 1)result += " ";
        }
        return result;
    }
};