#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> sortedNums = nums; // Create a copy of nums
        sort(sortedNums.begin(), sortedNums.end()); // Sort the copied array
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates
            if (i > 0 && sortedNums[i] == sortedNums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates
                if (j > i + 1 && sortedNums[j] == sortedNums[j - 1]) continue;
                long long left = j + 1;
                long long right = n - 1;
                while (left < right) {
                    long long sum = (long long)sortedNums[i] + (long long)sortedNums[j] + (long long)sortedNums[left] + (long long)sortedNums[right];
                    if (sum == target) {
                        result.push_back({sortedNums[i], sortedNums[j], sortedNums[left], sortedNums[right]});
                        // Skip duplicates
                        while (left < right && sortedNums[left] == sortedNums[left + 1]) ++left;
                        while (left < right && sortedNums[right] == sortedNums[right - 1]) --right;
                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
