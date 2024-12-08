class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by their end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by endTime
        });

        int result = 0, maxValue = 0;
        vector<pair<int, int>> endToMax; // Stores {endTime, maxValueTillNow}

        for (const auto& event : events) {
            int startTime = event[0], endTime = event[1], value = event[2];

            // Find the largest non-overlapping event using binary search
            auto it = lower_bound(endToMax.begin(), endToMax.end(), make_pair(startTime, 0));

            // If a valid non-overlapping event exists
            int bestNonOverlapValue = 0;
            if (it != endToMax.begin()) {
                --it; // Move to the valid event
                bestNonOverlapValue = it->second;
            }

            // Update the result to maximize the sum
            result = max(result, value + bestNonOverlapValue);

            // Update maxValue and store the current event's max value
            maxValue = max(maxValue, value);
            endToMax.emplace_back(endTime, maxValue);
        }

        return result;
    }
};
