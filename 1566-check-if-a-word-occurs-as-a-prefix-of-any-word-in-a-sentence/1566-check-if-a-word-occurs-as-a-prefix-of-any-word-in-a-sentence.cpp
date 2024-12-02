#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 1; // To keep track of the 1-based index
        
        while (stream >> word) { // Extract each word
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index;
            }
            index++;
        }
        return -1; // If no word matches
    }
};
