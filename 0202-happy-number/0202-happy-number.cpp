class Solution {
public:
    int nextele(int n){
        int sum = 0;
        while(n>0){
            int d = n % 10;
            sum += d * d;
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = nextele(n);
        while(fast != 1 && slow != fast){
            slow = nextele(slow);
            fast = nextele(nextele(fast));
        }
        return fast == 1;
    }
};