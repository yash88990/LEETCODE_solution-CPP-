class Solution {
public:
    string clearDigits(string s) {
        string result;
        for(char c : s){
            if(isdigit(c) && !result.empty()) {
                result.pop_back(); // Remove last added character
            } else if (!isdigit(c)) {
                result += c; // Append non-digit characters
            }
        }
        return result;
    }
};
