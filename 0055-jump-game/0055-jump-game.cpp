class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGoodIndex = nums.size() - 1; // Initialize the last good index to be the last index of the array
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= lastGoodIndex) {
                // If you can reach the last good index from the current index, update the last good index
                lastGoodIndex = i;
            }
        }
        // If the last good index reaches the first index, it means you can reach the last index from the first index
        return lastGoodIndex == 0;
    }
};
