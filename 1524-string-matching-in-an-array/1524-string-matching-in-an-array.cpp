class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        
        // Iterate through each word in the array
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                // Skip if comparing the word with itself
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // Once found as a substring, move to the next word
                }
            }
        }
        
        return result;
    }
};
