#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        int n = arr.size();
        
        // Check each triplet in the array
        for (int i = 0; i <= n - 3; ++i) {
            if (arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1) {
                return true;
            }
        }
        
        return false;
    }
};
