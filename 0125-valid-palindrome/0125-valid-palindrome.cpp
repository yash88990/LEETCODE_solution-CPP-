class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char ch : s){
            if(isalnum(ch)){
                temp += tolower(ch);
            }

        }

        int start = 0 , end = temp.size() - 1;
       while(start < end){
           if(temp[start++] != temp[end--])return false;
       }
       return true;
    }
};