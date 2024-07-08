class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Start with the base case (Josephus(1, k) = 0)
        for (int i = 1; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1; // Convert from 0-based to 1-based indexing
    }
};
