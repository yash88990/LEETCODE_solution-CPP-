class Solution {
public:
    int fib(int n) {
        //recc 
        //base case
        if(n <= 1 )return n;
        //recc
        return fib(n-1) + fib(n-2);
    }
};