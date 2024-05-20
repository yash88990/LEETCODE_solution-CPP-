class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // If the input vector is empty, return an empty string
        
        std::string prefix = strs[0]; // Initialize prefix with the first string
        
        // Iterate through the strings starting from the second one
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            // Compare characters of the current string with the prefix
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j); // Update prefix to the common substring
            if (prefix.empty()) break; // If prefix becomes empty, there's no common prefix, break
        }
        
        return prefix;
    }
};