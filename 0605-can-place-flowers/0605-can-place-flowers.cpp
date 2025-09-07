#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int s = flowerbed.size();
        
        for (int i = 0; i < s; i++) {
            if (flowerbed[i] == 0) {
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == s - 1 || flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; 
                    count++;
                }
            }
        }
        
        return count >= n;
    }
};
