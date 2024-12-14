#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long totalSubarrays = 0;
        int left = 0;
        multiset<int> window; // To track the min and max in the current window

        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);

            // Ensure the difference between max and min values in the window is ≤ 2
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }

            // Count the subarrays ending at 'right'
            totalSubarrays += right - left + 1;
        }

        return totalSubarrays;
    }
};
