class Solution {
public:
    int solve(int n){
        if(n <= 1)return n;
        return fib(n-1) + fib(n-2);

    }
    int fib(int n) {
        return solve(n);
       
    }
};