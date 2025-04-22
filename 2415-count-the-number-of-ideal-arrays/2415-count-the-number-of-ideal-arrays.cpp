class Solution {
public:
    int maxValue, sequenceLength;
    const int MOD = 1e9 + 7; // Modulus for the problem to handle large numbers

    // f = memoization table for results of dfs function with index i and count cnt
    // c = combinations table to store number of combinations to choose j elements from a set of size i
    vector<vector<int>> f;
    vector<vector<int>> c;

    // Main function that starts the process to count ideal arrays
    int idealArrays(int n, int maxValue) {
        this->maxValue = maxValue;
        this->sequenceLength = n;
        // Initialize memoization table with -1 to represent uncalculated states
        f.assign(maxValue + 1, vector<int>(16, -1));
        // Initialize combinations table with 0 values
        c.assign(n, vector<int>(16, 0));
      
        // Precalculate combinations using Pascal's triangle relationship
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i && j < 16; ++j) {
                c[i][j] = j == 0 ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }

        int ans = 0;
        // Sum the results of dfs for each number starting from 1 to maxValue
        for (int i = 1; i <= maxValue; ++i) {
            ans = (ans + dfs(i, 1)) % MOD;
        }
        return ans;
    }

    // Depth-first search function that calculates the number of ideal arrays 
    // ending with the integer 'i', having 'cnt' unique integers
    int dfs(int i, int cnt) {
        // If the result has already been calculated, return it to avoid recalculation
        if (f[i][cnt] != -1) return f[i][cnt];

        // Base result is the number of sequences that can be formed with 'cnt' copies of 'i'
        int res = c[sequenceLength - 1][cnt - 1];

        // If we can add more unique numbers to the array
        if (cnt < sequenceLength) {
            // Try to extend the sequence by adding multiples of 'i'
            for (int k = 2; i * k <= maxValue; ++k) {
                res = (res + dfs(i * k, cnt + 1)) % MOD;
            }
        }

        // Store the calculated result in the memoization table
        f[i][cnt] = res;
        return res;
    }
};
