#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end time
        });
        
        int removed = 0;
        int end_time = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end_time) {
                // Overlapping interval found, remove it
                ++removed;
            } else {
                // Non-overlapping interval, update end time
                end_time = intervals[i][1];
            }
        }
        
        return removed;
    }
};