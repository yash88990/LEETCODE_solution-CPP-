#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Sort the dictionary by length of roots
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        
        stringstream ss(sentence);
        string word;
        string result;
        
        // Process each word in the sentence
        while (ss >> word) {
            string replacement = word;
            for (const string& root : dictionary) {
                if (word.substr(0, root.length()) == root) {
                    replacement = root;
                    break;
                }
            }
            if (!result.empty()) {
                result += " ";
            }
            result += replacement;
        }
        
        return result;
    }
};
