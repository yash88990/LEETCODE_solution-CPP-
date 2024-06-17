class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0 ; a * a <= c ; a++ ){
            int b = sqrt(c- a * a );
            if(a * a + b * b == c ){
                return true ;
            }
        }
        return false ;
    }
};