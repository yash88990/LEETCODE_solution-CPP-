class Solution {

    public boolean canMake(int[] bloomDay, int m, int k, int day) {
        int flowers = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {

        int n = bloomDay.length;

        if ((long)m * k > n) return -1;

        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;

        for (int bloom : bloomDay) {
            left = Math.min(left, bloom);
            right = Math.max(right, bloom);
        }

        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
}