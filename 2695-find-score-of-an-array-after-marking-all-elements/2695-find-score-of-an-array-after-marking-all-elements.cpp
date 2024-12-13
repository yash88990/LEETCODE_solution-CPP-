#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        long long score = 0;

        // Min-heap to store (value, index) pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < n; ++i) {
            minHeap.emplace(nums[i], i);
        }

        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();

            // If already marked, skip
            if (marked[index]) continue;

            // Add to score and mark the element and its adjacent ones
            score += value;
            marked[index] = true;
            if (index > 0) marked[index - 1] = true;
            if (index < n - 1) marked[index + 1] = true;
        }

        return score;
    }
};
