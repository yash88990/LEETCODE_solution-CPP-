class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string result;

        vector<string> newword;

        while(ss >> word){
            newword.push_back(word);
        }
        reverse(newword.begin() , newword.end());
        for(int i = 0 ; i < newword.size() ; i++ ){
            result += newword[i];
            if(i < newword.size() - 1 ){
                result += " ";
            }
        }
        return result ;
    }
};