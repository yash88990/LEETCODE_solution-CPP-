class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> digits;

        // Create a list of digits from 1 to n
        for (int i = 1; i <= n; ++i) {
            digits.push_back(i);
        }

        // Calculate factorial of (n-1)
        int fact = 1;
        for (int i = 2; i < n; ++i) {
            fact *= i;
        }

        // Adjust k to 0-based indexing
        --k;

        // Iterate from n down to 1
        for (int i = n; i >= 1; --i) {
            // Calculate index of the digit to be selected
            int index = k / fact;
            
            // Update result by appending the selected digit
            result += to_string(digits[index]);
            
            // Remove the selected digit from the list
            digits.erase(digits.begin() + index);
            
            // Update k
            k %= fact;
            
            // Update fact
            if (i > 1)
                fact /= (i - 1);
        }

        return result;
    }
};