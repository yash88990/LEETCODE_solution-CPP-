class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int total = 0;
            for (int num : nums) {
                total += (num + mid - 1) / mid; // Equivalent to ceil(num / mid)
            }

            if (total <= threshold) {
                answer = mid;
                right = mid - 1; // Try smaller divisor
            } else {
                left = mid + 1; // Try larger divisor
            }
        }

        return answer;
    }
};
