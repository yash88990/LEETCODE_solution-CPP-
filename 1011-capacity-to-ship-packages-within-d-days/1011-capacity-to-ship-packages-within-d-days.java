class Solution {
public boolean can(int[] weights, int days, int capacity) {
    int dayCount = 1;
    int currLoad = 0;
    for (int w : weights) {
        if (currLoad + w > capacity) {
            dayCount++;
            currLoad = 0;
        }
        currLoad += w;
    }
    return dayCount <= days;
}

public int shipWithinDays(int[] weights, int days) {
    int l = Integer.MIN_VALUE;
    int r = 0;
    for (int w : weights) {
        l = Math.max(l, w); // max weight
        r += w;             // total weight
    }
    int ans = r;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (can(weights, days, m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
}

}
