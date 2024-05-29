#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        // Iterate through each string in strs
        for (const string& str : strs) {
            // Sort the string to use as a key
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            
            // Add the original string to the corresponding anagram group
            anagramGroups[sortedStr].push_back(str);
        }
        
        // Prepare the result vector
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
