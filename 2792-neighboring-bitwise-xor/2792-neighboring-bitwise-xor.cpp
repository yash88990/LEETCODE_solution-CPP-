class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Case 1: Assume original[0] = 0
        int originalFirst = 0;
        int current = originalFirst;
        for (int i = 0; i < n - 1; ++i) {
            current = derived[i] ^ current; // Compute original[i+1]
        }
        if ((current ^ originalFirst) == derived[n-1]) {
            return true;
        }

        // Case 2: Assume original[0] = 1
        originalFirst = 1;
        current = originalFirst;
        for (int i = 0; i < n - 1; ++i) {
            current = derived[i] ^ current; // Compute original[i+1]
        }
        if ((current ^ originalFirst) == derived[n-1]) {
            return true;
        }

        // If neither case works, return false
        return false;
    }
};
