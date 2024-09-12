class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Step 1: Store allowed characters in a set for quick lookup
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        // Step 2: Initialize a count for consistent strings
        int consistentCount = 0;
        
        // Step 3: Iterate over the words array
        for (const string& word : words) {
            bool isConsistent = true;
            
            // Step 4: Check if all characters in the word are allowed
            for (char c : word) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }
            
            // Step 5: If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }
        
        // Step 6: Return the count of consistent strings
        return consistentCount;
    }
};
