class Solution {

    public boolean canfinish(int[] piles, int h, int k){
        int hour = 0;

        for(int bananas : piles){
            hour += (bananas + k - 1) / k;
        }

        return hour <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int start = 1;

        int end = 0;
        for(int p : piles){
            end = Math.max(end, p);
        }

        while(start < end){
            int mid = start + (end - start) / 2;

            if(canfinish(piles, h, mid)){
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
}