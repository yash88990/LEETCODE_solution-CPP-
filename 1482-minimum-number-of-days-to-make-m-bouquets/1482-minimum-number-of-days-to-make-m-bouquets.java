class Solution {
    public boolean solve(int[] bloomDay, int m, int k, int mid) {
        int f = 0;
        int b = 0;
        for(int bloom : bloomDay){
            if(bloom <= mid){
                f++;
                if(f == k){
                    b++;
                    f = 0;
                }
            }else f = 0;
        }
        return b >= m;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        int ans = -1;
        if(((long) m * k) > n)return -1;
        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;
        for(int num : bloomDay){
            if(num < left)left = num;
            if(num > right)right = num;
        }
        while( left <= right){
            int mid = left + ( right - left)/2;
            if(solve(bloomDay , m , k , mid)){
                ans = mid;
                right = mid - 1;
            }else left = mid + 1 ;
        }
        return ans;
    }
}