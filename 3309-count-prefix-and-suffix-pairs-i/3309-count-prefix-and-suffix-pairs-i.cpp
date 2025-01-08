
class Solution {
public:
    // Helper function to check if str1 is both a prefix and suffix of str2
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n1 = str1.size(), n2 = str2.size();
        if (n1 > n2) return false; // str1 cannot be a prefix or suffix if it's longer
        
        // Check prefix condition
        for (int i = 0; i < n1; ++i) {
            if (str1[i] != str2[i]) return false;
        }
        
        // Check suffix condition
        for (int i = 0; i < n1; ++i) {
            if (str1[i] != str2[n2 - n1 + i]) return false;
        }
        
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        // Iterate over all pairs (i, j) with i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};