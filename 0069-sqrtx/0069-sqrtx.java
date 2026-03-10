class Solution {
    public int mySqrt(int x) {
        int s = 0 , e = x;
        long  ans = -1;
        while( s <= e){
            long  m = s + ( e - s )/2;
            long   sq = m * m;
            if(sq <= x){
                ans = m;
                s = (int)m +1 ;
            }else e = (int)m-1;
        }
        return (int)ans;
    }
}