class Solution {
public:
    double myPow(double x, int n) {
        // Base case: any number raised to the power of 0 is 1
        if (n == 0) return 1.0;

        // Handle the special case where n == INT_MIN
       if (n == INT_MIN) { 
        // Special case to handle INT_MIN since -n overflows
        return 1 / (myPow(x, -(n + 1)) * x);
    }

        // If n is negative, calculate the positive power and take the reciprocal
        if (n < 0) {
            return 1 / myPow(x, -n);
        }

        // Recursive case: use exponentiation by squaring
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half; // If n is even
        } else {
            return half * half * x; // If n is odd
        }
    }
};
