class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int cnt = 0;
        for(int i = 0 ; i < s ; i++){
            if(flowerbed[i] == 0){
                bool left = (i == 0 || flowerbed[i-1] == 0);
                bool right = ( i == s-1 || flowerbed[i+1] == 0);
                if(left && right){
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
        }
        return cnt >= n;
    }
};