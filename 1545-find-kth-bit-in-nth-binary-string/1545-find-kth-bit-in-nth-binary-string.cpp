
class Solution {
public:
    char findKthBit(int n, int k) {

        // S1 = "0"
        if (n == 1)
            return '0';

        // Length of Sn = 2^n - 1
        int len = (1 << n) - 1;

        // Middle position = 2^(n-1)
        int mid = 1 << (n - 1);

        // Middle bit is always 1
        if (k == mid)
            return '1';

        // Left half
        if (k < mid)
            return findKthBit(n - 1, k);

        // Right half
        // Find corresponding position in left half
        int newK = len - k + 1;

        // Invert the answer
        char ans = findKthBit(n - 1, newK);

        if (ans == '0')
            return '1';
        else
            return '0';
    }
};
