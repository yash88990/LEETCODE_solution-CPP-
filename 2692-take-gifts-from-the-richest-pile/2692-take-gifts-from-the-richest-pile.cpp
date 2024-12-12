#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Create a max-heap (priority queue with maximum at the top)
        priority_queue<int> maxHeap;

        // Push all the gifts into the max-heap
        for (int gift : gifts) {
            maxHeap.push(gift);
        }

        // Perform the operation k times
        while (k-- > 0) {
            // Get the maximum pile
            int maxGifts = maxHeap.top();
            maxHeap.pop();

            // Calculate the remaining gifts after leaving the floor of the square root
            int remainingGifts = floor(sqrt(maxGifts));

            // Push the remaining gifts back into the heap
            maxHeap.push(remainingGifts);
        }

        // Sum up all remaining gifts in the heap
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }

        return totalGifts;
    }
};
