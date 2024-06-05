class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int num = 0;
        int result = 0;
        int sign = 1; // 1 for positive, -1 for negative

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                nums.push(result);
                nums.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= nums.top(); // Previous sign
                nums.pop();
                result += nums.top(); // Previous result
                nums.pop();
            }
        }

        result += sign * num; // Add the last number

        return result;
    }
};