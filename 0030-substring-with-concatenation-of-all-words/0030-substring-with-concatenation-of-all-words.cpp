#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int word_length = words[0].length();
        int total_length = word_length * words.size();

        if (s.length() < total_length) return result;

        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        for (int i = 0; i < word_length; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen_words;
            while (right + word_length <= s.length()) {
                string word = s.substr(right, word_length);
                right += word_length;
                if (word_count.find(word) != word_count.end()) {
                    seen_words[word]++;
                    count++;
                    while (seen_words[word] > word_count[word]) {
                        string left_word = s.substr(left, word_length);
                        seen_words[left_word]--;
                        count--;
                        left += word_length;
                    }
                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    seen_words.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
