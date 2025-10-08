class Solution {
public:
    // Helper function to check if we can make 'm' bouquets in 'day' days
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int flowers = 0;     // count of consecutive bloomed flowers
        int bouquets = 0;    // count of bouquets formed

        for (int bloom : bloomDay) {
            if (bloom <= day) {   // if this flower is bloomed
                flowers++;
                // if we have enough flowers for one bouquet
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;  // reset for next bouquet
                }
            } else {
                flowers = 0;      // reset if flower not bloomed
            }
        }

        return bouquets >= m;     // true if we can make required bouquets
    }

    // Main function to find the minimum day
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // If total flowers are less than needed
        if ((long long)m * k > n) return -1;

        // Range of days (minimum to maximum bloom day)
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        // Binary Search on days
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;       // possible answer
                right = mid - 1; // try smaller day
            } else {
                left = mid + 1;  // need more days
            }
        }

        return ans;
    }
};
