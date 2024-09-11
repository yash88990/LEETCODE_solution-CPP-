class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the two numbers to find the differing bits
        int xorResult = start ^ goal;
        
        // Count the number of 1s in the XOR result (the differing bits)
        return __builtin_popcount(xorResult);
    }
};
