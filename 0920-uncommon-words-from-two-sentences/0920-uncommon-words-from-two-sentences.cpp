class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Create a map to store word frequencies
        unordered_map<string, int> wordCount;
        
        // Helper lambda to split words and count occurrences
        auto countWords = [&](const string& sentence) {
            stringstream ss(sentence);
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };
        
        // Count words in both sentences
        countWords(s1);
        countWords(s2);
        
        // Collect words that appear exactly once
        vector<string> result;
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
