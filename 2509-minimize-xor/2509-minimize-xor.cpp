class Solution {
public:
    int minimizeXor(int num1, int num2) {
          int count1 = __builtin_popcount(num1);
        int count2 = __builtin_popcount(num2);

        // If num1 has more set bits than num2, turn off set bits from the LSB side until they match
        while (count1 > count2) {
            // '&' operation with (num1 - 1) turns off the rightmost set bit in num1
            num1 &= (num1 - 1);
            // Decrement the set bit count for num1
            --count1;
        }

        // If num1 has fewer set bits than num2, turn on the unset bits from the LSB side until they match
        while (count1 < count2) {
            // '|' operation with (num1 + 1) turns on the rightmost unset bit in num1
            num1 |= (num1 + 1);
            // Increment the set bit count for num1
            ++count1;
        }

        // Return the modified num1 after trying to match the set bit count to num2
        return num1;
    }
};
