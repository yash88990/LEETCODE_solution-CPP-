import java.util.Stack;

class Solution {
    public String decodeString(String s) {
        Stack<Integer> counts = new Stack<>();
        Stack<String> strings = new Stack<>();
        String result = "";
        int count = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                // Accumulate the count (handles multi-digit numbers)
                count = count * 10 + (c - '0');
            } else if (c == '[') {
                // Push current state to stacks and reset
                counts.push(count);
                strings.push(result);
                result = "";
                count = 0;
            } else if (c == ']') {
                // Pop repeat count and previous string segment
                int repeatCount = counts.pop();
                StringBuilder repeatedString = new StringBuilder(result);
                String temp = result;
                
                // Perform the repetition
                for (int i = 1; i < repeatCount; i++) {
                    repeatedString.append(temp);
                }
                
                // Prepend the string segment before the current brackets
                result = strings.pop() + repeatedString.toString();
            } else {
                // Accumulate characters
                result += c;
            }
        }

        return result;
    }
}