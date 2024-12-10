
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        unordered_map<string, int> freq;

        // Generate all special substrings and count their frequencies
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            string temp = "";
            for (int j = i; j < n; ++j) {
                if (s[j] == c) {
                    temp += c;
                    freq[temp]++;
                } else {
                    break;
                }
            }
        }

        // Find the longest substring that appears at least thrice
        int maxLength = -1;
        for (auto &entry : freq) {
            if (entry.second >= 3) {
                maxLength = max(maxLength, (int)entry.first.length());
            }
        }

        return maxLength;
    }
};
