#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        stringstream ss(s);
        string word, result;
        vector<string> words;
        
        // Collect words into a vector
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 2: Reverse the vector of words
        reverse(words.begin(), words.end());
        
        // Step 3: Combine the reversed words into a single string
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};
