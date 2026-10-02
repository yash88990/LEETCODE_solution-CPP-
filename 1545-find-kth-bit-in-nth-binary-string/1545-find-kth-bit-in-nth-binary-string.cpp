class Solution {
public:
    char findKthBit(int n, int k) {
        //s1
        if(n == 1)return '0';
        //len
        int len = (1 << n)-1;
        //mid 
        int mid = 1 << (n-1);
        //mid always 1
        if(k == mid)return '1';
        //left half
        if(k < mid)return findKthBit(n-1 , k);
        //right half 
        int newK = len - k + 1 ;
        //invert
        char ans = findKthBit(n-1 , newK);
        if(ans == '0')return '1';
        else return '0';
    }
};