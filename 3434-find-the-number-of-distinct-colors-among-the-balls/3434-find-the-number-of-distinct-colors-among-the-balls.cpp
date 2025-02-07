#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; // Maps ball index to its color
        unordered_set<int> colorSet; // Tracks distinct colors
        vector<int> result;
        for (auto& query : queries) {
            int ball = query[0];
            int color = query[1];
            // If the ball already has a color, check if it needs to be removed from the set
            if (ballColor.find(ball) != ballColor.end()) {
                int prevColor = ballColor[ball];
                // Remove previous color if no other ball has it
                bool found = false;
                for (auto& pair : ballColor) {
                    if (pair.second == prevColor && pair.first != ball) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    colorSet.erase(prevColor);
                }
            } 
            // Assign new color and update color set
            ballColor[ball] = color;
            colorSet.insert(color);
            // Store current distinct color count
            result.push_back(colorSet.size());
        }
        
        return result;
    }
};
