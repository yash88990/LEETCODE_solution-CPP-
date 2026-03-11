class Solution {
public int splitArray(int[] nums, int k) {

    int l = 0, r = 0;

    for (int x : nums) {
        l = Math.max(l, x);
        r += x;
    }

    int ans = r;

    while (l <= r) {

        int m = l + (r - l) / 2;

        int count = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= m) {
                sum += x;
            } else {
                count++;
                sum = x;
            }
        }

        if (count <= k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
}


}
