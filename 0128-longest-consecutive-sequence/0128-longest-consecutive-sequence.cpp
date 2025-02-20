class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty case

        sort(nums.begin(), nums.end()); // Sort the array

        int ans = 1, count = 1, n = nums.size();
        int start = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue; // Skip duplicates

            if (nums[i] == start + 1) { // Consecutive element found
                count++;
            } else { // Reset count on a non-consecutive element
                ans = max(ans, count);
                count = 1;
            }

            start = nums[i]; // Update start value
        }

        return max(ans, count); // Final update for last sequence
    }
};
