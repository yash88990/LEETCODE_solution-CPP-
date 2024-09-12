class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        // Reverse half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // Compare the first half with the reversed second half
        // For even number of digits: reversedHalf == x
        // For odd number of digits: reversedHalf / 10 == x (since middle digit doesn't matter)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
