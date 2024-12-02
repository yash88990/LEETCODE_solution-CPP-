class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        // Iterate in chunks of 2k
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse the first k characters in each 2k block
            int end = min(i + k - 1, n - 1);
            reverse(s.begin() + i, s.begin() + end + 1);
        }
        
        return s;
    }
};
