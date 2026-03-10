import java.util.Stack;

class Solution {
    public String removeStars(String s) {
        Stack<Character> stk = new Stack<>();

        // Process each character in the string
        for (char c : s.toCharArray()) {
            if (c == '*') {
                if (!stk.isEmpty()) {
                    stk.pop(); // Remove the closest non-star character to the left
                }
            } else {
                stk.push(c); // Retain non-star characters
            }
        }

        // Construct the resulting string from the stack
        StringBuilder result = new StringBuilder();
        while (!stk.isEmpty()) {
            result.append(stk.pop());
        }

        // The characters are in reverse order, so reverse the result
        return result.reverse().toString();
    }
}