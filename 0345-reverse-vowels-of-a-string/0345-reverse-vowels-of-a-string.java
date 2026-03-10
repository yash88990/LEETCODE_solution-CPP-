class Solution {
    // Helper method to check if a character is a vowel
    public boolean isvowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
        int n = s.length();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            // Move start pointer until a vowel is found
            while (start < end && !isvowel(chars[start])) {
                start++;
            }
            // Move end pointer until a vowel is found
            while (start < end && !isvowel(chars[end])) {
                end--;
            }

            if (start < end) {
                // Swap the vowels
                char temp = chars[start];
                chars[start] = chars[end];
                chars[end] = temp;
                
                start++;
                end--;
            }
        }

        return new String(chars);
    }
}