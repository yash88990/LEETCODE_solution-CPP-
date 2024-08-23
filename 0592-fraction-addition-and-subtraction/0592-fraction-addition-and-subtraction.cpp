#include <iostream>
#include <string>
#include <numeric> // For std::gcd
using namespace std;

class Solution {
public:
    // Function to compute the Greatest Common Divisor (GCD)
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    // Function to parse and perform fraction addition and subtraction
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;  // Start with 0/1 as the initial fraction
        int i = 0, n = expression.size();
        
        while (i < n) {
            // Read the sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }
            
            // Read the numerator
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            
            // Skip the '/'
            i++;
            
            // Read the denominator
            int denom = 0;
            while (i < n && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }
            
            // Apply the sign to the numerator
            num *= sign;
            
            // Add the current fraction (num/denom) to the overall result (numerator/denominator)
            numerator = numerator * denom + num * denominator;
            denominator *= denom;
            
            // Reduce the fraction
            int g = gcd(abs(numerator), denominator);
            numerator /= g;
            denominator /= g;
        }
        
        // If the result is an integer, return it as "x/1"
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
