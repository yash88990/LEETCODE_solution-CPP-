#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minValue = arrays[0].front();
        int maxValue = arrays[0].back();
        int maxDistance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate the distance using the current array's elements
            maxDistance = max(maxDistance, abs(arrays[i].back() - minValue));
            maxDistance = max(maxDistance, abs(maxValue - arrays[i].front()));

            // Update minValue and maxValue with the current array's front and back elements
            minValue = min(minValue, arrays[i].front());
            maxValue = max(maxValue, arrays[i].back());
        }

        return maxDistance;
    }
};
