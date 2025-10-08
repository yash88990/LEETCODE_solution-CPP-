class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (int x : nums) {
            l = max(l, x);
            r += x;
        }
        int ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 1, s = 0;
            for (int x : nums) {
                if (s + x <= m) {
                    s += x;
                } else {
                    cnt++;
                    s = x;
                }
            }
            if (cnt <= k) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};