class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin() , s.end());

        // string str ="";
        // for(int i = s.size() - 1 ; i >= 0 ; i--){
        //     str += s[i];
        // }
        // for(int i = 0 ; i < str.size() ; i++){
        //     s[i] = str[i];
        // }


        int start = 0 , end = s.size() - 1;
        while(start < end){
            swap(s[start] , s[end]);
            start++;
            end--;
        }

        

    }
};