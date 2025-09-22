#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        if (word1.length() != word2.length())
            return false;
        
        std::unordered_map<char, int> count1, count2;
        std::unordered_set<char> chars1, chars2;
        
        for (char c : word1) {
            count1[c]++;
            chars1.insert(c);
        }
        
        for (char c : word2) {
            count2[c]++;
            chars2.insert(c);
        }
        
        std::vector<int> freq1, freq2;
        for (auto& pair : count1) {
            freq1.push_back(pair.second);
        }
        
        for (auto& pair : count2) {
            freq2.push_back(pair.second);
        }
        
        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2 && chars1 == chars2;
    }
};