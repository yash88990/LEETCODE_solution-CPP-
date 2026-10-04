class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                if (minOpen > 0)
                    minOpen--;
                maxOpen--;
                if (maxOpen < 0)
                    return false;
            } else { // c == '*'
                maxOpen++;
                if (minOpen > 0)
                    minOpen--;
            }
        }
        
        return minOpen == 0;
    }
};