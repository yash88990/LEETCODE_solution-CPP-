
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int left = 0, right = 0;
        int maxLen = 0;
        int zeroCount = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLen = std::max(maxLen, right - left);
            right++;
        }

        return maxLen;
    }
};