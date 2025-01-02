#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        // Agar character 'a', 'e', 'i', 'o', ya 'u' hai, toh true return karo
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    // Helper function to check if a word is a vowel string
    bool isVowelString(const string& s) {
        // Ek word tabhi vowel string hoga jab uska pehla aur aakhri character vowel ho
        return isVowel(s.front()) && isVowel(s.back());
    }

    // Main function to calculate results for each query
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        // Prefix sum array banayenge to efficiently count vowel strings
        vector<int> prefixSum(n + 1, 0);

        // Prefix sum array ko calculate karo
        for (int i = 0; i < n; ++i) {
            // Agar current word vowel string hai, toh prefix sum badhao
            prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
        }

        // Result array jisme har query ka answer store karenge
        vector<int> result;

        // Har query ke liye prefix sum ka use karke result nikalenge
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            // Prefix sum ka difference use karke range [l, r] ke vowel strings count karo
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        // Sabhi queries ka result return karo
        return result;
    }
};
