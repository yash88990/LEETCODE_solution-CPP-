#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;
        
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        // Sort robots by their positions
        sort(robots.begin(), robots.end());

        stack<int> rightMovingRobots;
        vector<int> resultHealths(n, -1);
        
        for (int i = 0; i < n; ++i) {
            int position = get<0>(robots[i]);
            int health = get<1>(robots[i]);
            char direction = get<2>(robots[i]);
            int index = get<3>(robots[i]);

            if (direction == 'R') {
                rightMovingRobots.push(i);
            } else {
                while (!rightMovingRobots.empty()) {
                    int rightIndex = rightMovingRobots.top();
                    int rightHealth = get<1>(robots[rightIndex]);

                    if (rightHealth < health) {
                        rightMovingRobots.pop();
                        health -= 1;
                        get<1>(robots[rightIndex]) = -1; // This robot is destroyed
                    } else if (rightHealth == health) {
                        rightMovingRobots.pop();
                        health = -1; // Both robots are destroyed
                        get<1>(robots[rightIndex]) = -1;
                        break;
                    } else {
                        health = -1; // This robot is destroyed
                        get<1>(robots[rightIndex]) -= 1;
                        break;
                    }
                }

                if (health != -1) {
                    resultHealths[index] = health;
                }
            }
        }

        while (!rightMovingRobots.empty()) {
            int index = rightMovingRobots.top();
            rightMovingRobots.pop();
            resultHealths[get<3>(robots[index])] = get<1>(robots[index]);
        }

        // Collect the surviving robots' healths in the original order
        vector<int> survivors;
        for (int health : resultHealths) {
            if (health != -1) {
                survivors.push_back(health);
            }
        }

        return survivors;
    }
};
