class Solution {

public int smallestDivisor(int[] nums, int threshold) {

    int s = 1;
    int e = Integer.MIN_VALUE;

    for (int num : nums) {
        e = Math.max(e, num);
    }

    int ans = 0;

    if (nums.length == threshold) return e;

    while (s <= e) {

        int m = s + (e - s) / 2;
        int total = 0;

        for (int num : nums) {
            total += (num + m - 1) / m;   // ceiling division
        }

        if (total <= threshold) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    return ans;
}

}
