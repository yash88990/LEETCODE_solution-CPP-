class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0); // Difference array for shifts

        // Build the difference array
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int change = (direction == 1) ? 1 : -1;

            delta[start] += change;
            if (end + 1 < n) {
                delta[end + 1] -= change;
            }
        }

        // Apply cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += delta[i];
            int shiftAmount = (cumulativeShift % 26 + 26) % 26; // Handle wraparounds
            s[i] = 'a' + (s[i] - 'a' + shiftAmount) % 26; // Shift character
        }

        return s;
    }
};
