class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end()); // Reverse the string
        
        // Create a new string which is s + '#' + rev_s
        string combined = s + "#" + rev_s;
        
        // Build KMP table for the combined string
        int n = combined.length();
        vector<int> lps(n, 0); // Longest prefix suffix table

        // Building the KMP table
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1]; // length of the previous longest prefix suffix
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1]; // fall back to the previous lps value
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j; // set lps for current index
        }

        // Use the value from the last position of the lps array to determine
        // the number of characters we need to append in the front.
        int to_add = s.length() - lps[n - 1];
        return rev_s.substr(0, to_add) + s;
    }
};
