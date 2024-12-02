#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;

        for (int i = 0; i <= n; ++i) {
            // When a space or the end of the string is encountered
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i); // Reverse the word
                start = i + 1; // Move to the start of the next word
            }
        }

        return s;
    }
};
