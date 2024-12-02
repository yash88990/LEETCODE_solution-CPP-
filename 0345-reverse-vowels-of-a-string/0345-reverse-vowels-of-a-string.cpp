#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        // Helper function to check if a character is a vowel
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int left = 0, right = s.length() - 1;

        // Two-pointer approach to reverse vowels
        while (left < right) {
            // Move left pointer until a vowel is found
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            // Move right pointer until a vowel is found
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
