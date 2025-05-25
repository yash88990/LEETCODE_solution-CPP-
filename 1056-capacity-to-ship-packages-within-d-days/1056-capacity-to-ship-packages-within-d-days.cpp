class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                dayCount++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, mid, days)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
