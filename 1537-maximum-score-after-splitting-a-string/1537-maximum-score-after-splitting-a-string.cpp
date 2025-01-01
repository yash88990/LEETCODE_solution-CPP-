class Solution {
public:
    int maxScore(string s) {
        int countOne = 0; // Count of ones in the string
        for (char c : s) {
            if (c == '1') countOne++;
        }
        
        int maxScore = 0, countZeroes = 0, leftScore = 0, rightScore = countOne;
        
        // Iterate through the string, excluding the last position to ensure both substrings are non-empty
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                countZeroes++;
            } else {
                rightScore--;
            }
            // Calculate score for the current split
            int score = countZeroes + rightScore;
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};
