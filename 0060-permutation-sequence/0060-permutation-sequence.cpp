class Solution {
public:
    string getPermutation(int n, int k) {
        // Initialize the numbers and factorial array
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
            fact *= i; // Compute n!
        }
        
        // Adjust k to 0-based index
        k -= 1;

        string result = "";
        for (int i = 0; i < n; ++i) {
            fact /= (n - i); // Factorial for remaining digits
            int index = k / fact; // Find the index of the current number
            result += to_string(numbers[index]); // Add the selected number to result
            numbers.erase(numbers.begin() + index); // Remove used number
            k %= fact; // Update k for the next group
        }

        return result;
    }
};
