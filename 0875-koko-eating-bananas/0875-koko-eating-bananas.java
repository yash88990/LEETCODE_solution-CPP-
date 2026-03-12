class Solution {
    public boolean caneat(int[] piles ,int h , int mid){
        int hour = 0;
        for(int i = 0 ; i < piles.length ; i++){
            hour += (piles[i] + mid - 1) / mid;
        }
        return hour <= h;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int start = 1 , end = Integer.MIN_VALUE;
        for(int num : piles)if(num > end)end = num;
        while( start < end){
            int mid = start + ( end - start)/2;
            if(caneat(piles , h , mid))end = mid;
            else start = mid + 1 ;
        }
        return start;
    }
}