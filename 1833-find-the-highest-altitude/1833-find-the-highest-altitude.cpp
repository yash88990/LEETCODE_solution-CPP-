#include <vector>
#include <algorithm>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int gainValue : gain) {
            currentAltitude += gainValue;
            maxAltitude = std::max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};
