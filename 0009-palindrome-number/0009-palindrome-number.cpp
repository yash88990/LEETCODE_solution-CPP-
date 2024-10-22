class Solution {
public:
    bool isPalindrome(int x) {
        // If the number is negative, it's not a palindrome
        if (x < 0) return false;

        // Store the original value of x
        int original = x;
        long newx = 0; // Use long to handle overflow

        // Reverse the digits of the number
        while (x != 0) {
            int digit = x % 10;
            newx = newx * 10 + digit;
            x /= 10;
        }

        // Check if the reversed number is equal to the original number
        return newx == original;
    }
};
