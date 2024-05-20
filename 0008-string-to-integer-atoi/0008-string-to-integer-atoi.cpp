class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, result = 0;
        
        // Step 1: Ignore leading whitespace
        while (s[i] == ' ')
            i++;
        
        // Step 2: Check for sign
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Read digits until non-digit character or end of string
        while (isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Step 4: Convert digits into an integer
            // Check for overflow/underflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // Apply sign
        return result * sign;
    }
};