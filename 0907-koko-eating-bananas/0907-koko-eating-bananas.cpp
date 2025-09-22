class Solution {
public:
        int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1; // Minimum possible eating speed
        int right = max_element(piles.begin(), piles.end()); // Maximum possible eating speed

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                // If it's possible to finish within h hours with eating speed mid or lower, try smaller eating speeds
                right = mid;
            } else {
                // If it's not possible to finish within h hours with eating speed mid, try higher eating speeds
                left = mid + 1;
            }
        }

        // At the end of the binary search, left and right converge to the minimum eating speed that allows Koko to finish within h hours
        return left;
    }

private:
    bool canFinish(const std::vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int bananas : piles) {
            // Calculate hours needed to finish eating bananas at speed k for current pile
            hours += (bananas + k - 1) / k;
        }
        return hours <= h; // Return true if Koko can finish within h hours
    }
};
