class Solution {
public:
    void reverseString(vector<char>& s) {
        // //method 1 
        // reverse(s.begin() , s.end());

        //method 2 
        int start = 0 , end = s.size() -1;
        while(start <= end){
            swap(s[start++] , s[end--]);
        }
    }
};