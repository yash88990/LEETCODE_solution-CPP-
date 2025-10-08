class Solution {
public:
    int mySqrt(int x) {
     int s = 0 , e = x-1 ;
     if( x == 1)return 1;
     long long int ans = 0;
     while( s <= e){
            long long int m = s + ( e - s )/2;
            long long int sq = m * m;
            if(sq == x)return m;
            if(sq < x){
                ans = m;
                s = m + 1 ;
            }else{
                e = m - 1;
            }
     }   
     return ans;
    }
};