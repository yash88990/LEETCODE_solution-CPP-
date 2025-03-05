class Solution {
public:
    long long coloredCells(int n) {
        long long count = 1 , jump = 4;
        while(n > 1){
            count += jump;
            jump += 4;
            n--;
        }
        return count;
    }
};