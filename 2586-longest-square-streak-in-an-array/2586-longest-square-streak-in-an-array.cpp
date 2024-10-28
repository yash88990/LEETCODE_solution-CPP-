#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxStreak = -1;

        for (int num : nums) {
            long long current = num;
            int streakLength = 0;

            // Build a square streak for the current number
            while (numSet.find(current) != numSet.end()) {
                streakLength++;
                current *= current; // Move to the next squared value
                if (current > 1e5) break; // Prevent overflow and limit to valid range
            }

            // Check if the streak length is at least 2
            if (streakLength >= 2) {
                maxStreak = max(maxStreak, streakLength);
            }
        }

        return maxStreak;
    }
};
