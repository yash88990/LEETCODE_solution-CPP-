class Solution {
public:
    bool solve(string &s, int start, int end) {
        // Base case: If pointers cross, it is a palindrome
        if (start >= end) return true;

        // Skip non-alphanumeric characters from the start
        if (!isalnum(s[start])) return solve(s, start + 1, end);

        // Skip non-alphanumeric characters from the end
        if (!isalnum(s[end])) return solve(s, start, end - 1);

        // Compare characters (ignoring case)
        if (tolower(s[start]) != tolower(s[end])) return false;

        // Recur for the remaining substring
        return solve(s, start + 1, end - 1);
    }

    bool isPalindrome(string s) {
        return solve(s, 0, s.size() - 1);
    }
};
