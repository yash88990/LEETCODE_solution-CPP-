class Solution {
public:
    int solverecc(int n){
        if(n<= 1)return n;

        return solverecc(n-1) + solverecc(n-2); 
    }
    int fib(int n) {
        return solverecc(n);
        
    }
};