class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        // Compare each bit of a, b, and c
        for (int i = 0; i < 32; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            // Check if the ith bit of (a OR b) is different from the ith bit of c
            if ((bit_a | bit_b) != bit_c) {
                // If both a and b have the ith bit different from c, we need 2 flips
                if (bit_a == 1 && bit_b == 1)
                    flips += 2;
                // Otherwise, we only need 1 flip
                else
                    flips += 1;
            }
        }
        return flips;
    }
};