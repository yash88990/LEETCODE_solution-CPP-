class Solution {
public:
    int mySqrt(int x) {
        int start = 0 , end = x, ans = -1;
        if(x == 1)return 1;
        while(start <= end){
            long long int mid = start + (end - start)/2;
            long long int sq = mid * mid;
            if(sq == x)return mid;
            else if (sq < x){
                ans = mid;
                start = mid + 1 ;
            }else end = mid - 1 ;
        }
        return ans;
    }
};