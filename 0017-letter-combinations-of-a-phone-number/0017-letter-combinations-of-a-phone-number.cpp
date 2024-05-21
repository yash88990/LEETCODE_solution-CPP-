class Solution {
public:
    void backtrack(vector<string>& combinations, const string& digits, const vector<string>& mappings, string& current, int index) {
        // If we have processed all digits, add the current combination to the result
        if (index == digits.size()) {
            combinations.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = mappings[digits[index] - '0'];
        
        // Iterate through each letter and recursively generate combinations
        for (char letter : letters) {
            // Append the current letter to the current combination
            current.push_back(letter);
            // Recursive call with the next digit
            backtrack(combinations, digits, mappings, current, index + 1);
            // Backtrack: remove the last character to try the next letter
            current.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // Mapping of digits to letters
        vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations;
        // Base case: if the input string is empty
        if (digits.empty()) return combinations;
        // Start backtracking from the first digit
        string current;
        backtrack(combinations, digits, mappings, current, 0);
        return combinations;
    }
};