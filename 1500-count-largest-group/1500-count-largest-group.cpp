class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37, 0); // Max digit sum is 9+9+9+9 = 36 for n <= 10000
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            count[sum]++;
            maxSize = max(maxSize, count[sum]);
        }

        int result = 0;
        for (int c : count) {
            if (c == maxSize) result++;
        }

        return result;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
