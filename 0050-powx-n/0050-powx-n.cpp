class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; // Base case: x^0 = 1

        // Handle the special case of INT_MIN
        if (n == INT_MIN) {
            // Divide n by 2 to stay within bounds and square the result
            double half = myPow(x, INT_MIN / 2);
            return half * half;
        }

        if (n < 0) {
            x = 1 / x;
            n = -n; // Safe since n != INT_MIN here
        }

        double half = myPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
