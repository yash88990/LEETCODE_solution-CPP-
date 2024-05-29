class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the intervals by their start times
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals;
        
        // Initialize the first interval as the current interval to merge
        mergedIntervals.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last interval in the merged intervals
            vector<int>& lastInterval = mergedIntervals.back();
            
            // If the current interval overlaps with the last interval in the merged list
            if (intervals[i][0] <= lastInterval[1]) {
                // Merge the current interval with the last interval by updating the end time
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                // If it doesn't overlap, add the current interval to the list
                mergedIntervals.push_back(intervals[i]);
            }
        }
        
        return mergedIntervals;
    }
};
