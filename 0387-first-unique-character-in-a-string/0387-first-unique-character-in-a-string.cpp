#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount; // To store the frequency of each character

        // Count the frequency of each character
        for (char c : s) {
            charCount[c]++;
        }

        // Find the first character with a frequency of 1
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        // If no unique character is found, return -1
        return -1;
    }
};

/**
 * Example usage:
 * Solution sol;
 * string s = "leetcode";
 * int result = sol.firstUniqChar(s);
 * // result will be 0
 */
