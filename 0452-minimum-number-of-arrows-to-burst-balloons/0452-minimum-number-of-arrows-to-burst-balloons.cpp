#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort the balloons by their end points
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1; // Initialize the number of arrows needed
        int endPos = points[0][1]; // Initialize the end position of the first balloon
        
        for (int i = 1; i < points.size(); i++) {
            // If the start position of the current balloon is beyond the current arrow's position
            // Shoot another arrow at the end position of the current balloon
            if (points[i][0] > endPos) {
                arrows++; // Increase the number of arrows needed
                endPos = points[i][1]; // Update the end position of the current arrow
            }
        }
        
        return arrows;
    }
};
