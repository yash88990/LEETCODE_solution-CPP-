#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1; 
        int right = *max_element(piles.begin(), piles.end()); 
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) right = mid;
            else  left = mid + 1; 
        }
        return left;
    }

private:
    bool canFinish(const std::vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;
        }
        return hours <= h; 
    }
};