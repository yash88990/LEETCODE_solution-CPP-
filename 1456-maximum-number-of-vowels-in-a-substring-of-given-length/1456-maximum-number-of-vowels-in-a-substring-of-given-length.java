class Solution {
    // Helper method to check if a character is a vowel
    public boolean isvowel(char ch) {
        char c = Character.toLowerCase(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public int maxVowels(String s, int k) {
        int vowelcount = 0;
        int n = s.length();

        // Step 1: Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (isvowel(s.charAt(i))) {
                vowelcount++;
            }
        }

        int maxi = vowelcount;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            // Subtract if the character leaving the window was a vowel
            if (isvowel(s.charAt(i - k))) {
                vowelcount--;
            }
            // Add if the new character entering the window is a vowel
            if (isvowel(s.charAt(i))) {
                vowelcount++;
            }

            maxi = Math.max(vowelcount, maxi);
        }

        return maxi;
    }
}