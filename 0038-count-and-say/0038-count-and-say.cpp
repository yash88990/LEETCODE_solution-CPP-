class Solution {
public:
    string countAndSay(int n) {
         if (n == 1) {
            return "1"; // Base case
        }

        // Recursive call to get previous term in the sequence
        string prev = countAndSay(n - 1);
        
        string result = ""; // Initialize result for current term

        int count = 1;
        char say = prev[0]; // Initialize current digit

        // Iterate through the previous term to generate the current term
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == say) {
                count++; // Increase count if digit is the same
            } else {
                // Append count and digit to result
                result += to_string(count) + say;
                say = prev[i]; // Update current digit
                count = 1; // Reset count
            }
        }

        // Append the last count and digit to result
        result += to_string(count) + say;

        return result;
    }
};