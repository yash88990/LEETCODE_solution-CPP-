#include <vector>
#include <unordered_set>
#include <utility>
#include <string>

class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        // Directions: North, East, South, West
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;  // Starting position
        int directionIndex = 0;  // Initially facing North
        int maxDistanceSquared = 0;

        // Store obstacles in a set for quick lookup
        std::unordered_set<std::string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(std::to_string(obs[0]) + "," + std::to_string(obs[1]));
        }

        // Process each command
        for (const int& cmd : commands) {
            if (cmd == -1) {
                // Turn right
                directionIndex = (directionIndex + 1) % 4;
            } else if (cmd == -2) {
                // Turn left
                directionIndex = (directionIndex + 3) % 4;  // Equivalent to (directionIndex - 1) % 4
            } else {
                // Move forward cmd units
                for (int step = 0; step < cmd; ++step) {
                    int newX = x + directions[directionIndex].first;
                    int newY = y + directions[directionIndex].second;
                    
                    // Check if the new position is an obstacle
                    if (obstacleSet.find(std::to_string(newX) + "," + std::to_string(newY)) == obstacleSet.end()) {
                        // No obstacle, move the robot
                        x = newX;
                        y = newY;
                        // Update the maximum distance squared from the origin
                        maxDistanceSquared = std::max(maxDistanceSquared, x * x + y * y);
                    } else {
                        // Obstacle encountered, stop moving in this direction
                        break;
                    }
                }
            }
        }
        
        return maxDistanceSquared;
    }
};
