class Solution {
public:
    int getLucky(string s, int k) {
        // Step 1: Convert the string to its numeric representation
        string numeric_representation = "";
        for (char c : s) {
            int numeric_value = c - 'a' + 1;  // Convert char to corresponding number
            numeric_representation += to_string(numeric_value);  // Append to the numeric string
        }

        // Step 2: Perform the transformation k times
        int result = 0;
        for (char c : numeric_representation) {
            result += c - '0';  // Sum all digits in the initial numeric string
        }

        // Perform the transformation k-1 more times
        while (--k > 0) {
            int new_result = 0;
            while (result > 0) {
                new_result += result % 10;  // Sum the digits of the current result
                result /= 10;
            }
            result = new_result;  // Update the result after each transformation
        }

        return result;
    }
};
