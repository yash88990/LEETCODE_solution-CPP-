#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::vector<int> minutes;
        
        // Convert time points to minutes since midnight
        for (const std::string& time : timePoints) {
            int hours = std::stoi(time.substr(0, 2));
            int mins = std::stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the minutes
        std::sort(minutes.begin(), minutes.end());
        
        // Initialize the minimum difference as the maximum possible
        int minDiff = INT_MAX;
        
        // Calculate minimum difference between adjacent times
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = std::min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Consider the circular difference
        minDiff = std::min(minDiff, 1440 - (minutes.back() - minutes.front()));
        
        return minDiff;
    }
};
