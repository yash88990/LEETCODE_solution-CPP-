class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        bool seenDigitAfterE = true; // To handle cases like "2e".

        // Trim leading and trailing whitespaces
        size_t start = 0, end = s.length() - 1;
        while (start <= end && std::isspace(s[start])) start++;
        while (end >= start && std::isspace(s[end])) end--;

        // Check if the string is empty after trimming
        if (start > end) return false;

        for (size_t i = start; i <= end; ++i) {
            char c = s[i];

            if (std::isdigit(c)) {
                seenDigit = true;
                seenDigitAfterE = true;
            } else if (c == '.') {
                // '.' can't appear after another '.', or after 'e'
                if (seenDot || seenE) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                // 'e' can't appear after another 'e', or if no digits have been seen yet
                if (seenE || !seenDigit) return false;
                seenE = true;
                seenDigitAfterE = false; // Reset seenDigitAfterE flag
            } else if (c == '+' || c == '-') {
                // '+' or '-' can only appear at the beginning of the number or after 'e'
                if (i > start && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else {
                return false; // Any other character is invalid
            }
        }

        // The number is valid if at least one digit has been seen, and if after 'e' there's a valid digit
        return seenDigit && seenDigitAfterE;
    }
};