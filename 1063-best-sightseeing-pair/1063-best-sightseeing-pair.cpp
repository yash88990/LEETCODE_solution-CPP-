class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0; // To store the maximum score
        int maxLeft = values[0]; // Initially, maxLeft is values[0] + 0
        
        for (int j = 1; j < values.size(); ++j) {
            // Calculate the score using maxLeft and values[j]
            maxScore = std::max(maxScore, maxLeft + values[j] - j);
            
            // Update maxLeft for the next iteration
            maxLeft = std::max(maxLeft, values[j] + j);
        }
        
        return maxScore;
    }
};
