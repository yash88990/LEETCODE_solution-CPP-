#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Store indices of elements in the current window
        vector<int> result; // Store the maximums for each window

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove indices of all elements smaller than the current element
            // as they are not useful anymore
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // If the window has reached size k, add the maximum to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

/**
 * Example usage:
 * Solution sol;
 * vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
 * int k = 3;
 * vector<int> result = sol.maxSlidingWindow(nums, k);
 * // result will be [3, 3, 5, 5, 6, 7]
 */
