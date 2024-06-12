#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos; // Update ones for bits that appear once but not twice
            twos = (twos ^ num) & ~ones; // Update twos for bits that appear twice but not once
        }
        return ones;
    }
};
